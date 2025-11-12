#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5;
const int MAXL=5e6;
int n,q;
string str1,str2;
map<string,string>mp;
int main(void) {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>str1>>str2;
		mp[str1]=str2;
	}
	int len=-1;
	while(q--) {
		cin>>str1>>str2;
		len=str1.size();
		str1=" "+str1;
		str2=" "+str2;
		int lim1=0,lim2=0;
		for(int i=1; i<=len; i++) {
			if(str1[i]!=str2[i]) {
				lim1=i;
				break;
			}
		}
		for(int i=len; i>=1; i--) {
			if(str1[i]!=str2[i]) {
				lim2=i;
				break;
			}
		}
		long long ans=0;
		for(int i=1; i<=lim1; i++) {
			for(int j=lim2; j<=len; j++) {
				string t1="",t2="";
				for(int k=1; k<i; k++) {
					t1+=str1[k];
					t2+=str2[k];
				}
				if(t1==t2) {
					t1="",t2="";
					for(int k=i; k<=j; k++) {
						t1+=str1[k];
						t2+=str2[k];
					}
					if(mp[t1]==t2) {
						t1="",t2="";
						for(int k=j+1; k<=len; k++) {
							t1+=str1[k];
							t2+=str2[k];
						}
						if(t1==t2) {
							++ans;
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
