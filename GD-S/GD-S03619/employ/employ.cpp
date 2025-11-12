#include<bits/stdc++.h>
using namespace std;
int n,m,w=0,t=0,ans=0,fal=0,lo[555],l0[555],c[555];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) lo[++t]=i;
		if(s[i-1]=='0') l0[++w]=i-1;
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=t && i<=w;i++){
		swap(c[lo[i]],c[l0[i]]);
	}
	for(int i=1;i<=n;i++){
		if(fal>=c[i]){
			fal++;
			continue;
		}
		if(s[i-1]=='1'){
			ans++;
		}else{
			fal++;
		}
	}
	cout<<ans%998244353;
	return 0;
}
