#include<bits/stdc++.h>
using namespace std;

int n,k,ans,maxr=-1,m;
int a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i!=0)a[i]=a[i]^a[i-1];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j>=0;j--){
			if(j<=maxr){
				break;
			}
			if((j==0 and a[i]==k) or (a[i]^a[j-1])==k){
				ans++;
				maxr=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
