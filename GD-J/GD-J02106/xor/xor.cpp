#include<bits/stdc++.h>
using namespace std;
int n,k,a[510000],ans,b[510000];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
	}
	int cs=0;
	for(int i=1;i<=n;i++){
		if(cs%2==0&&b[i]==k){
			cs++;
			ans++;
		}
		else if(cs%2!=0&&b[i]==0){
			cs++;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
hua-love×¨Êô
hua-love ´óÀÐorz 
*/
