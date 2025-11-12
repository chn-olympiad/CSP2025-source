#include<bits/stdc++.h>
#include<cmath>
using namespace std;
long long n,k,a[500005],ansyi=0,ansling=0,ans=0;
bool Akkk=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k!=0){
		Akkk=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(Akkk&&a[i]!=1){
			Akkk=0;
		}
		if(a[i]==1){
			ansyi++;
		}else if(a[i]==0){
			ansling++;
		}
	}
	if(Akkk){
		cout<<0;
		return 0;
	}
	if(k==0){
		cout<<ansling;
		return 0;
	} 
	if(k==1&&(ansyi+ansling)==n){
		cout<<ansyi;
		return 0; 
	}else if(k==0&&(ansyi+ansling)==n){
		cout<<ansling;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
		}else if(a[i+1]!=k){
			a[i+1]&=a[i];
		}
	}
	cout<<ans+1;
	return 0;
}
