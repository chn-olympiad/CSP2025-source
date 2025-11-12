#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct pp{
	string s1,s2;
}s[200005],t[200005];
ll n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	for(int _=1;_<=q;_++){
		string t1,t2;
		ll ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			string t=t1;
			if(t1.find(s[i].s1)!=-1&&t2.find(s[i].s2)!=-1){
				int p=t1.find(s[i].s1);
				//cout<<p<<" ";
				for(int j=0;j<s[i].s2.size();j++){
					t[j+p]=s[i].s2[j];
					//cout<<s[i].s2[j]<<endl;
				}
				//cout<<t<<" "<<t2<<endl; 
				if(t==t2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
