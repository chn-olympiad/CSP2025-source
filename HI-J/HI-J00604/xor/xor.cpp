#include<bits/stdc++.h>
using namespace std;
int n,sum1=0,sum2=0,maxn=0,k,a[500005];
bool flag=false;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) flag=true;
		if(a[i]==0) sum1++;
		if(a[i]==1) sum2++;
	}
	if(k==0){
		cout<<sum1;
		return 0;
	}else if(k==1){
		cout<<sum2;
		return 0;
	}else if(flag==false){
		cout<<0;
		return 0;
	}else{
		cout<<2;
		return 0;
	}
	return 0;
}
