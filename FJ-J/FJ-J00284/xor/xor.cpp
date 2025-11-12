#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010];
long long yh[500010],v[500010],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	yh[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		yh[i]=yh[i-1]^a[i];
		if(a[i]==k){
			sum++;
			v[i]=1;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			bool flag=0;
			for(int l=j;l<=j+i;l++){
				if(v[l]){
					flag=1;break;
				}
			}
			if(flag) continue;
			if(yh[j]^yh[j+i]==k){
				sum++;
				for(int l=1;l<=i;l++){
					v[j+l-1]=1;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}