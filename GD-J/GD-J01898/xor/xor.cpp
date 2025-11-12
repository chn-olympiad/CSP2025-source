#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}q[500005];
bool cmp(node a,node b){
	return a.y<b.y;
}
int n,k,ans,top;
int a[500005],s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
				q[++top]={i,j};
			}
		}
	}
	sort(q+1,q+top+1,cmp);
	int now=0;
	for(int i=1;i<=top;i++){
		if(q[i].x>now){
			ans++;
			now=q[i].y;
		}
	}
	cout<<ans;
	return 0;
}
//xor
