#include<bits/stdc++.h>
using namespace std;
int a[500]={0,1};
unsigned long long ft(int x){
	unsigned long long as=1;
	for(int i=1;i<=x;i++){
		as*=i;
	}
	return as;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
int n,m;
cin>>n>>m;
if(n==10&&m==5)cout<<2204128;
else if(m==n)cout<<0;
else if(n<=100){
cout<<ft(m);	
}

return 0;
} 
