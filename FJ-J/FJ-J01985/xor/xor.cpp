#include<bits/stdc++.h>
using namespace std;

const int maxn=500005;
int n,k,a[maxn];
int l[maxn],r[maxn],sum=1,ans=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			int num=a[i];
			for(int k=1;k<=j;k++){
				num^=a[i+k];
			}
			
			if(num==k){
				l[sum]=i;
				r[sum]=i+j;
				sum++;
			}
		}
	}
	sum-=1;
	cout<<sum; 
	return 0;
}
