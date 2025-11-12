#include<bits/stdc++.h>
using namespace std;
const int N=200001;
struct jj{
	string a,b;
	int c;
};
jj s[N],t;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,j,i,ans,k;
	string s1,s2;
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		s[i].c=s[i].a.size();
	}
	for(i=1;i<=q;i++){
		ans=0;
		cin>>t.a>>t.b;
		t.c=t.a.size();
		for(j=1;j<=n;j++){
			for(k=0;k<=t.c-s[j].c;k++){
				if(t.a[k]==s[j].a[0]){
					s1=t.a.substr(0,k);
					s2=t.a.substr(k+s[j].c);
					if(s1+s[j].b+s2==t.b){
						ans+=1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}