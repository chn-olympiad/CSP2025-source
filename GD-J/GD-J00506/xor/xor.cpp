#include<bits/stdc++.h>
using namespace std;
int a[500005],ans,s,n,k;
void dg(int x){
	if(x==n+1){
		s=max(ans,s);
		return;
	}for(int i=x;i<=n;i++){
		int f=-1;
		for(int j=i;j<=n;j++){
			if(f==-1)f=a[j];
			else f=(a[j]^f);
			if(f==k){
				ans++;
				dg(j+1);
				ans--;
			}
		}
	}
}int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dg(1);cout<<s;
	return 0;
}
