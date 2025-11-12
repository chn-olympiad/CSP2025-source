#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,q,i,j,s[N],l,len,ans;bool b;
string s1[N],s2[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		s[i]=s1[i].size();
	}
	while(q--){
		cin>>t1>>t2;
		len=t1.size(),ans=0;
		for(i=0;i<len;i++){
			if(i&&t1[i-1]!=t2[i-1])break;
			for(j=0;j<n;j++)
				if(s1[j][0]==t1[i]&&t2[i]==s2[j][0]&&i+s[j]<=len){
					b=1;
					for(l=0;l<s[i];l++)
						if(t1[i+l]!=s1[j][l]||t2[i+l]!=s2[j][l]){
							b=0;break;
						}
					l+=i;
					while(b&&l<len){
						if(t1[l]!=t2[l])b=0;
						l++;
					}
					ans+=b;
				}
		}
		cout<<ans<<'\n';
	}
}
