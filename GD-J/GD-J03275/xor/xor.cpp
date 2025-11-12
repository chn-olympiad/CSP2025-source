#include<bits/stdc++.h>
using namespace std;
int n,k,ans,ans1,ans2;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		if(a[i]==1) ans2++;
		if(a[i]==0) ans1++;
		if(a[i]==k){
			ans++;
			a[i]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1&&a[i+1]==1){
			a[i]=0;
			a[i+1]=0;
			ans1++;
		}
	}
	int s;/*
	for(int i=1;i<=n;i++){
		for(int j=i,f=1;j<=n;j++){
			s=a[i];
			for(int o=i+1;o<=j;o++){
				if(a[o]<0)
				{
					f=0;
					break;
				 } 
				s^=a[o];
			}
			if(s==k&&f){
				ans++;
				//cout<<i<<" "<<j<<"\n";
				for(int o=i;o<=j;o++){
					a[o]=-1;
				}
				break;
			}
		}
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1,f=1;j<=n;j++){
			s=a[j];
			if(s<0)
				continue;
			for(int o=j+1;o<=j+i&&o<=n;o++){
				if(a[o]<0)
				{
					f=0;
					break;
				 } 
				s^=a[o];
			}
			if(s==k&&f){
				ans++;
				cout<<i<<" "<<j<<"\n";
				for(int o=i;o<=j;o++){
					a[o]=-1;
				}
				break;
			}
		}
	}
	if(k==1)
		cout<<ans2;
	else if(k==0)
		cout<<ans1;
	else
		cout<<ans;
	return 0;
}


