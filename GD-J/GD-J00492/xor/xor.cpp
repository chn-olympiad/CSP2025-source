#include<iostream>
using namespace std;
long long n,k,a[5000010],b[5000010],d[1010][1010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		if(a[i]==k)d[i][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int l=1,r=i;r<=n;l++,r++){
			long long c=0;
			if((b[r]^b[l-1])==k)c=1;
			for(int k=l;k<=r;k++){	
				d[l][r]=max(d[l][r],max(c,d[l][k]+d[k+1][r]));
			}
		}
	}
	cout<<d[1][n];
	return 0;
}
