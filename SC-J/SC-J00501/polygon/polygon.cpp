#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,a[N];
long long sum=0,m=998244353; 
long long num;

void f(int i,long long sum,int k,int c){
	if(i==n+1){
		if(sum>2*a[k]&&c>=3)	num=(num+1)%m;
		return ;
	}
	f(i+1,sum+a[i],i,c+1);
	f(i+1,sum,k,c);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1);
	f(1,0,0,0);
	cout<<num;
	return 0;
}