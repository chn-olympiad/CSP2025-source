#include<bits/stdc++.h>
#define int long long
#define fi(n) for(int i=1;i<=n;i++)
using namespace std;
const int MAXN=5e5+5;
int n,k,kq=1;
int a[MAXN],c[MAXN];
map<int,int> b;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	fi(n){
		cin>>a[i];
	}
	int l=1,r=0;
	int sum=0;
	fi(n){
		sum^=a[++r];
		if(b[sum^k]==kq||sum==k){
			//cout<<r<<' '; 
			l=r+1;
			kq++;
			
			sum=0;
			continue;
		} 
		b[sum]=kq;
		
	}
	cout<<kq-1;

    return 0;
}

