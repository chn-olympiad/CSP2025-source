#include<iostream>
#include<vector>
using namespace std;
const int N=5e5+5;
int n,k,x,ans,len,a[N],CL[N],mp[N*4];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(!mp[x])CL[++len]=x;
		mp[x]=1;
		x^=a[i];
		if(mp[x^k]){
			for(int i=1;i<=len;i++)mp[CL[i]]=0;
			x=len=0;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
