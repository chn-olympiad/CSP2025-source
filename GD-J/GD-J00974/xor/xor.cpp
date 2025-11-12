#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,k,cnt;
ll a[N],vis[N]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			vis[i]=1;
			cnt++;
		}
	}
//	cout<<cnt;
	for(int i=1;i<n;i++){
		if(vis[i]==1){
			continue;
		}
		if(vis[i+1]==1){
			i++;
			continue;
		}
		ll sum=a[i],j=i+1;
		while(vis[j]!=1 && j<=n){
			sum=sum xor a[j];
//			cout<<j<<" "<<sum<<endl;
			if(sum==k){
//				cout<<i<<" "<<j<<endl;
				for(int l=i;l<=j;l++){
					vis[l]=1;
				}
				cnt++;
				break;
			}
			j++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

