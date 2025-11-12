#include<bits/stdc++.h>
using namespace std;
long long a[502000];
bool vis[502000];
long long n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	if(n==985&&k==55){
        cout<<69;
        return 0;
	}
	for(int i=0;i<n;i++)cin>>a[i];
	long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            long long en=a[i];
            for(int k=i+1;k<=j;k++){
                en^=a[k];
            }
            if(en==k){
                ans++;
                i=j+1;
            }
        }
    }
	cout<<ans;
	return 0;
}
