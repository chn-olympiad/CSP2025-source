#include<bits/stdc++.h>
using namespace std;
struct sb{
	long long x,y;
}b[500005];
bool cmp(sb a,sb b){
	return a.y<b.y;
}
int k,n,a[500005],m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum^=a[i];
			if(sum==k){
				b[m].x=i;b[m++].y=j;
			}
		}
	}
	sort(b,b+m,cmp);
	int ans=0,sum=0,j=0;
	ans=1;
	for(int i=b[j].y;j<m;){
		while(b[++j].x<i){
			
		}
		cout<<b[i].x<<' '<<b[j].y<<' ';
		i=b[j].y;
		ans++;
	}
	cout<<ans;
} 
