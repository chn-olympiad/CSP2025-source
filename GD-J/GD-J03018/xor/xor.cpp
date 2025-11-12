#include<bits/stdc++.h>
using namespace std;
int a1,a2,n,a[500011],ans=0,k,vivi;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)vivi++;
		if(a[i]!=1)a1=1;
		if(a[i]!=1&&a[i]!=0)a2=1;
	}if(a1!=1)cout<<n/2;
	else if(a2!=1){
		if(k==1)cout<<vivi;		
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				if(a[i]==1&&a[i+1]==1)ans++,i++;
			}cout<<ans;
		} 
	}return 0;
}
