#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y;
}d[5005];
long long n,k,ans;
long long a[5005],s[5005][5005];	
bool cmp(node q,node p){
	return q.x>p.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		s[i][i]=a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<i;j++){
			for(long long k=j;k<=i;k++){
				s[i][j]=s[i][j]^a[k];
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=i;j++){
			if(s[i][j]==k){
				ans++;
				d[i].x=j;
				d[i].y=i;
			}
		}
	}
	sort(d+1,d+1+n,cmp);
	int i=1;
	while(d[i].x!=0){
		int j=i+1;
		while(d[j].x!=0 && j<i){
			if(d[j].y>d[i].y) ans--;
			j++;
		}
		i++;
	}
	cout<<ans;
	return 0;
}
