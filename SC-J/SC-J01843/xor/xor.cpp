#include<bits/stdc++.h>
using namespace std;

const int N=5*1e+5;

int n,k;
int a[N+10];
int f[N+10];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	
	int sum=0;
	if(k==0){
		for(int i=1;i<=n;i++)
			if(a[i]==0)	sum++;
		cout<<sum;
	}else if(k==1){
		for(int i=1;i<=n;i++)
			if(a[i]==1)	sum++;
		cout<<sum;
	}
	
	
	return 0;
}
