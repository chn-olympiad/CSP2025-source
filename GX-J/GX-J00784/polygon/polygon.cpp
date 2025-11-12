#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	if(n==1){
		cout<<0;
		return 0;
	}if(n==2){
		cout<<0;
		return 0;
	}
	return 0;
}
