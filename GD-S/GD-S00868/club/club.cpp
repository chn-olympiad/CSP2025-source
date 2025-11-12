#include<bits/stdc++.h>
using namespace std;
struct club{
	int a,b,c,d;
}s[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	long long ans,cnt;
	while(t--){
		ans=0,cnt=0;
		int n,a1=0,a2=0,a3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			ans+=max(s[i].a,max(s[i].b,s[i].c));
		}
		cout<<ans<<endl;
	}
	return 0;
}
