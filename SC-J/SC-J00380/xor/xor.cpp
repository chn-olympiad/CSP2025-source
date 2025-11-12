#include <bits/stdc++.h>
using namespace std;
long long n,a[101000],b[101000],k,ans;
bool f=1,f2=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
		if(a[i]!=1&&a[i]!=0){
			f2=0;
		}
	}
	if(f){
		cout<<n/2;
	}else if(f2){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(a[i]==1&&a[i+1]==1){
					ans++;i++;
				}
			}
			cout<<ans;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans;
		}
	}else{
		while(1) cout<<"I AK IOI\n";
	}
	return 0;
}