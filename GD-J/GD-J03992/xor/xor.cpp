#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int num[500003];
int c[500003];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int sum=num[l];
			for(int k=l+1;k<=r;k++){
				sum=sum^num[k];
			}
			if(sum==k){
				//cout<<"start "<<l<<" to "<<r<<" result "<<sum<<" YES"<<endl;
				ans++;
			}
			//cout<<"start "<<i<<" to "<<j<<" result "<<sum<<" NO"<<endl;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
