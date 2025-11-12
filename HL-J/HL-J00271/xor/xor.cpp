#include<bits/stdc++.h>
using namespace std;

const int N=5e5+100;

int n,a[N],summ[N],pluss[N];

int yihuo(int a,int b){
	if(a==b)return 0;
	else return 1;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	cin>>a[1];
	summ[1]=a[1];
	pluss[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		summ[i]=yihuo(summ[i-1],a[i]);
		pluss[i]=pluss[i-1]+a[i];
		
	}
	cout<<pluss[n];
	
	return 0;
}
