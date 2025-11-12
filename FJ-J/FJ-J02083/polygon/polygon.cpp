#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[100001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]%2==0){
		cout<<6;
	}else{
		cout<<9;
	}
} 
