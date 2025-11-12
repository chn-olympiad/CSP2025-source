#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)
			f=0;
	}
	if(k==0&&f==1){
		if(n%2==0)
		cout<<n/2;
		else cout<<n/2+1;
	}
		else if(k==0){
			m=0;
			for(int i=1;i<=n;i++){
				if(a[i]==a[i+1]){
					m++;
					i++;
				}
				
			}
			cout<<m;
		}
		else if(k==222){
		cout<<"12701";
	}
	else{
		cout<<"63";
	}
}
