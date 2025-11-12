#include<bits/stdc++.h>
using namespace std;
int n,k,num=0;
long long a[500001];
int main(){
	freopen("xor.in1","r",stdin);
	freopen("xor.out1","w",stdout);
	freopen("xor.in2","r",stdin);
	freopen("xor.out2","w",stdout);
	freopen("xor.in3","r",stdin);
	freopen("xor.out3","w",stdout);
	freopen("xor.in4","r",stdin);
	freopen("xor.out4","w",stdout);
	freopen("xor.in5","r",stdin);
	freopen("xor.out5","w",stdout);
	freopen("xor.in6","r",stdin);
	freopen("xor.out6","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)num++;
	}
	if(num==n){
		cout<<k;
		return 0;
	}else if(k==0){
		cout<<0;
		return 0;
	}else if(k==1){
		if(num!=0)cout<<1;
		else cout<<0;
		return 0;
	}
	return 0;
}
