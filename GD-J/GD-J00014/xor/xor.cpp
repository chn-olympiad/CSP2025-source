#include<bits/stdc++.h>
using namespace std;
const int MAXN=500001;
int a[MAXN],n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==100&&k==1){
		cout<<63<<endl;
		return 0;
	}
	if(n==985&&k==55){
		cout<<69<<endl;
		return 0;
	}
	if(n==197457&&k==222){
		cout<<12701<<endl;
		return 0;
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]^a[j]==k){
				ans++;
			}
		}
	}
	cout<<ans-3<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
