#include<bits/stdc++.h>
using namespace std;
int a[500005],b,i,l,n,m,ans,k;
string s;
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==1)cout<<0;
	else if(n==2)cout<<1;
	else{
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		if(k==0){
			for(i=1;i<=n;i++){
				if(a[i]==0)ans++;
				else if(a[i]==1&&a[i+1]==1){
					ans++;i++;
				}
			}
		}
		else{
			for(i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
		}
		cout<<ans;
	}
	return 0;
} 
