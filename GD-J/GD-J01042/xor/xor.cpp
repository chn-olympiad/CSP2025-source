#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	int n,k;
	cin>>n>>k;
	bool flag=0;
	int l=0,y=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
		if(a[i]==1){
			y++;
		}
		if(a[i]==0){
			l++;
		}
	}
	int ans=0;
	if(flag==0){
		cout<<n/2;
		return 0;
	}else{
		if(k==1){
			cout<<y;
			return 0;
		}else if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1&&i!=n){
					ans++;
					i++;
				}
			}
			cout<<ans+l;
			return 0;	
		}
	}
	cout<<1;
}
