#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
long long a[N],b[N];
struct dd{
	long long l,r;
}c[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		b[i]=b[i-1]^a[i];
	}
	int  f=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[j]^b[i-1])==k){
				//cout<<i<<" "<<j<<" "<<(b[j]^b[i-1])<<"\n";
				c[f].l=i;
				c[f].r=j;
				f++;
			}
		}
	}
	long long maxx=INT_MIN,sum=1;
	for(int i=0;i<f-1;i++){
		long long rr=0;
		sum=0;
		for(int j=i+1;j<f;j++){
			if(c[j].l>rr){
				rr=c[j].r;
				sum++;
			}
		}
		maxx=max(sum,maxx);
	}
	cout<<maxx;
	return 0;
}