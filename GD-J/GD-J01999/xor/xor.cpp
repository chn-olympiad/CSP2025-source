#include<bits/stdc++.h>
using namespace std;
int n;
long long k,a[500005],sum=0;
bool c[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)sum++,c[i]=1;
	}
	for(int i=1;i<=n-1;i++){
		if(c[i])continue;
		int s=a[i],j=i+1;
		while(!c[j]&&j<=n){
			s^=a[j];
			if(s==k){
				sum++;
				for(int l=i;l<=j;l++)c[l]=1;
				break;
			}
			j++;
		}
	}
	cout<<sum;
	return 0;
}
