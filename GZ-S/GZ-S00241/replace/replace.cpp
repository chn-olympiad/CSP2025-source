//GZ-S00241 安顺市第二高级中学 李舜杰 
#include<bits/stdc++.h>
#define N 200005
typedef long long  LL;
using namespace std;
const int mod=998244353;
int n,q,ans,tp1[N],tp2[N];
string s[N][5],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie();cout.tie();
    cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>s[i][1]>>s[i][2];
    	for(int j=0;j<s[i][q].size();j++){
    		if(s[i][1][j]=='b') tp1[i]=j;
    		if(s[i][2][j]=='b') tp2[i]=j;
		}
	}
	for(int t=1;t<=q;t++){
		ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int tp=t1.find(s[i][1]);
			if(tp>=0&&tp<n){
				string tpp=t1;
				for(int j=tp,kk=0;j<tp+s[i][1].size();j++,kk++){
					tpp[j]=s[i][2][kk];
				}
				if(tpp==t2) ans++;
				}
			}
			cout<<ans<<endl;
		}
	return 0;
}

