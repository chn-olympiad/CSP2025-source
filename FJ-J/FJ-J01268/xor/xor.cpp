#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int a[1000000],s,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			s=a[l];
			for(int i=l+1;i<=r;i++){
				s=s^a[i];
			}
			if(s==k) ans++;
		}
	}
	cout<<ans;
	return 0;
	
}
