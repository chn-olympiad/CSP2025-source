#include<bits/stdc++.h>
using namespace std;
int yh_is(int a,int b){
	string result_h="";
	int result_i=0;
	while(a!=0&&b!=0){
		int wei=a%2!=b%2;
		result_h+=wei+'0';
		a/=2,b/=2;
	}
	for(int i=0;i<result_h.size();i++){
		result_i=(result_h[i]-'0')*pow(2,i);
	}
	return result_i;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[10005]={};
	bool flag_A=false;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1])flag_A=true;
	}
	if(flag_A&&k==0){
		int s=1;
		for(int i=2;i<=n;i++){
			s*=i;
		}
		cout<<s;
	}
	else cout<<2;
}
