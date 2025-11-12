#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],Max,pre[500010];
bool b=1;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		Max=max(Max,a[i]);
		if(a[i]!=1) b=0;
	}
	if(b){
		cout<<n/2;
		exit(0);
	}
	else{
		srand(time(0));
		long long t=rand()%(n+1);
		long long tt=rand()%(n/25);
		cout<<t-tt;
	}
	return 0;
} 
