#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,a[2342],maxx=0,ans=0,l=0,j;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=3;i<=n;i++){
		for(j=1;j<=n-i+1;j++);
		{
		maxx=0,ans=0;
			for(int s=j;s<=j+i-1;s++){
			maxx=max(maxx,a[j]);
			ans+=a[j];
		}
		if(ans>maxx*2) l++;	
			
		}
	}
	cout<<l;
	return 0;
}

