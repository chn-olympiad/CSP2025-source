#include<bits/stdc++.h>
using namespace std;
string s;
int a[810],b[810],num=0,n,m;
long long sum;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n-1;i++){
		cin>>s[i];
		if(s[i]=='1'){
			num++;
		}
		b[i]=num;
	}
	if(b[n-1]==n){
		sum=1;
		for(int i=1;i<=n;i++){
			sum*=i;
		}
		sum=sum%998244353;
		cout<<sum;
	}
	for(int j=1;j<=n;j++){
		cin>>a[j]; 
	}
	return 0; 
} 
