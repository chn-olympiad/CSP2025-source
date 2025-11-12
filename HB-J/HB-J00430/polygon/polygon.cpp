#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
void zuhe(int x,int step,int m,int maxn){
	if(step<x){
		for(int i=m;i<=n;i++){
			maxn+=a[i];
			zuhe(x,step+1,i+1,maxn+a[i]);
		}	
	}
	else {
		int l=step,c=2*maxn;
		while(c>a[l])l++;
		ans+=l-step+1;
	}
}
int main()
{
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		zuhe(i,1,1,0);
	}
    cout<<ans%998%244%353;
	return 0;	
}
