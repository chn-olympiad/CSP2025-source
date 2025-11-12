#include<bits/stdc++.h>
using namespace std;
int n,k;int a[500010],tmp,sf,cnto,bo,ro,ans,mas;
bool f=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnto++;
		}
		if(a[i]>1){
			f=0;
		}
		if(a[i]==1&&a[i-1]==1){
			bo++;
		}else{
			if(bo%2==1){
				bo++;
			} 
			ro=ro+bo/2;
		}
	}
	if(k==1&&f==1){
		cout<<cnto<<endl;
		return 0;
	}else if(cnto==n&&k==0){
		cout<<n/2;
		return 0;
	}else if(f==1){
		cout<<n-cnto+ro;
		return 0;
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			tmp=tmp^a[i];
			if(tmp==k){
				ans++;
				tmp=0;
			}
		}
		mas=max(mas,ans);
		ans=0;
	}
	cout<<mas<<endl;
	
	return 0;
}
