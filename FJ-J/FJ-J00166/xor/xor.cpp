#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long k,a[int(5e5)+5],sum;
bool vis[int(5e5)+5],flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
			vis[i]=1;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			if(vis[j]) continue;
			sum=a[j];
			flag=0;
			for(int m=j+1;m<=j+i;m++){
				if(vis[m]){
					flag=1;
					break;
				}
				sum=sum^a[m];
		 }
			if(!flag){
				if(sum==k){
					cnt++;
					for(int m=j;m<=j+i;m++) vis[m]=1;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}

