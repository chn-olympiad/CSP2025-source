#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[500010],b[500010]={ };
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			b[i]=1;
			ans++;
		}
	}
	//¿ìÏÂÔØBetter Luogu°É£¡ 
	cout<<ans; 
	return 0;
}
