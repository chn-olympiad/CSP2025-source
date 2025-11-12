#include<bits/stdc++.h>

using namespace std;

#define LL long long

const int N=2e5+6;

LL T,n,m,k,sum,cnt,ans;
LL A[N],C[N];
string s[N],t[N],str1,str2,str;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
	}
	for(int i=1;i<=m;i++){
		cin>>str1>>str2;
		if(str1.size()!=str2.size()){
			cout<<0<<endl;
		}
		else if(max(str1.size(),str2.size())>2000){
			cout<<0<<endl;
		}
		else{
			k=str1.size();ans=0;
			for(int j=0;j<k;j++){
				if(str1[j]!=str2[j]){
					for(int ap=1;ap<=n;ap++){
						LL op=k-j;
						if(op<(LL)s[ap].size()){
							continue;
						}
						else{
							str=str1.substr(j,s[ap].size());
							//cout<<str<<' '<<s[ap]<<' '<<t[ap]<<' '<<(t[ap]+str1.substr(j+s[ap].size(),n-j))<<' '<<str2.substr(j,n-j+1)<<endl;
							if(str==s[ap]&&(t[ap]+str1.substr(j+s[ap].size(),n-j))==str2.substr(j,n-j+1)){
								ans++;
							}
						}
					}
					break;
				}
				else{
					for(int ap=1;ap<=n;ap++){
						LL op=k-j;
						if(op<(LL)s[ap].size()){
							continue;
						}
						else{
							str=str1.substr(j,s[ap].size());
							//cout<<str<<' '<<s[ap]<<' '<<t[ap]<<' '<<(t[ap]+str1.substr(j+s[ap].size(),n-j))<<' '<<str2.substr(j,n-j+1)<<endl;
							if(str==s[ap]&&t[ap]+str1.substr(j+s[ap].size(),n-j)==str2.substr(j,n-j+1)){
								ans++;
							}
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	
	
	
	return 0;
}
