#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#define ll long long
#define fg cout<<"！！！！！！！！！！！！！！！！！！"<<endl
using namespace std;
const int N=2e5+5,mod1=998244353,mod2=1e9+7,base1=131,base2=13331;
int n,q;
int l[N],r[N];
string s1[N],s2[N];
string a,b;
string ts(int x){
	string ss="";
	while(x){
		ss+=(x%10)+'0';
		x/=10;
	}
	return ss;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
//	if(q==1||n<=1000){
		for(int i=1;i<=n;i++){
			if(s1[i].size()!=s2[i].size()){
				l[i]=-1;
				continue;
			}
			while(l[i]<s1[i].size()&&s1[i][l[i]]==s2[i][l[i]]) l[i]++;
			r[i]=s1[i].size()-1;
			while(r[i]>=0&&s1[i][r[i]]==s2[i][r[i]]) r[i]--;
		}
		while(q--){
			ll ans=0;
			cin>>a>>b;
			int L=0,R=a.size()-1;
			while(L<a.size()&&a[L]==b[L]) L++;
			while(R>=0&&a[R]==b[R]) R--;
			for(int i=1;i<=n;i++){
				if(l[i]==-1) continue;
				if(s1[i]==a&&s2[i]==b){
					ans++;
					continue;
				}
				if(l[i]>L||s1[i].size()-r[i]>a.size()-R||R-L!=r[i]-l[i]){
					continue;
				}
				int y=1;
				for(int j=l[i],x=0;j<=r[i];j++,x++){
					if(s1[i][j]!=a[L+x]||s2[i][j]!=b[L+x]){
						y=0;
						break;
					}
				}
				if(y){
					for(int j=1;j<=l[i];j++){
						if(s1[i][l[i]-j]!=a[L-j]){
							y=0;
							break;
						}
					}
					for(int j=1;j<=s1[i].size()-1-r[i];j++){
						if(s1[i][r[i]+j]!=a[R+j]){
							y=0;
							break;
						}
					}
					if(y){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
//	}else{
		
//	}
	return 0;
}
/*

*/
