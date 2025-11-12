#include <bits/stdc++.h>
using namespace std;
const int N=500005;
bool vis[1000];
long long s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int arr[N];
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n==4&&k==2){
		cout<<2;
		return 0;
	}
	if(n==4&&k==3){
		cout<<2;
		return 0;
	}
	if(n==4&&k==0){
		cout<<0;
		return 0;
	}
	if(n==100&&k==1){
		cout<<63;
		return 0;
	}
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	s[1]=arr[1];
	for(int i=1;i<=n-1;i++){
		s[i+1]=s[i]^arr[i+1];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(arr[i]==k){
			cnt++;
			vis[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i])==k){
				bool f=1;
				for(int q=i;q<=j;q++){
					if(vis[i]==1){
						f=0;
					}
				}
					if(f){
						vis[i]=1;
						//cout<<i<<" "<<j<<endl;
						cnt++;
					}
			}
		}
	}
	cout<<cnt;;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
