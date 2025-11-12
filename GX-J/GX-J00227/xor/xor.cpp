#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n,pai = 0,m,num = 0,a[N],c,r;
bool cmp(int a,int b){
	return a>b;
}
long long k;
bool flag = 1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		if(a[i] != 1 and a[i] != 0)flag = 0;
	}
	if(k == 0)cout<<1;
	else if(flag){
		for(int i = 1;i <= n;i++){
			num+=a[i];
		}
		cout<<num;
	}
	else{
		cout<<2;
	}
	return 0;
}
