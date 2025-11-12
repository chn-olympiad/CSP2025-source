#include<bits/stdc++.h> //CSP-J AK me 
using namespace std;
int n,k,ans;
int a[500005];
int s[500005];
bool color[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=(a[i]^s[i-1]);
	//for(int i=1;i<=n;i++) cout<<s[i]<<' ';
	//cout<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int flag=0;
			for(int l=j-i+1;l<=j;l++) if(color[l]){
				flag=1;break;
			}
			if(flag) continue;
			if((s[j]^s[j-i])==k){
				//cout<<j-i+1<<' '<<j<<' '<<(s[j]^s[j-i])<<'\n';
				ans++;
				for(int l=j-i+1;l<=j;l++) color[l]=true;
			}
		}
	}
	cout<<ans;
	return 0;
}














void AKAK(){
	long/* lougu super super long long lougu */long rp;
	while(1) rp++;
	return;
}
