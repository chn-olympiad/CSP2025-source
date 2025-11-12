#include<bits/stdc++.h>
using namespace std;
int n,MAX,s;
bool bj;
int a[5001];
void go(int he,int ge_shu,int da,int t){
	if(ge_shu>=n)return;
	for(int i=t+1;i<=n;i++){
		if(ge_shu+1>=3){
			if(he+a[i]>max(da,a[i])*2){
				//cout<<he<<" "<<ge_shu<<endl;
			s++;	
		}
	}
		go(he+a[i],ge_shu++,max(da,a[i]),i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)bj=1;
		if(MAX<a[1])MAX=a[i];	
	}
	if(bj==0){
		cout<<n-2;
		return 0;
	}
	else if(n==3){
		if(a[1]+a[2]+a[3]>MAX*2){
			cout<<"1";
		}
		return 0;
	}
	else {
		s=0;
		go(0,1,0,1);
		cout<<s%998244353 ;	
	}
	return 0;
}

