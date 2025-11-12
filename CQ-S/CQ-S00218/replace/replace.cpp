#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,q;
string s1[maxn],s2[maxn];
string t1,t2;
int c1[maxn][2],c2[maxn][2],d1[2],d2[2];
bool f1,f2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}for(int i=1;i<=n;i++){
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='a')c1[i][f1]++;
			else f1=true;
		}for(int j=0;j<s2[i].size();j++){
			if(s2[i][j]=='a')c2[i][f2]++;
			else f2=true;
		}
	}while(q--){
		cin>>t1>>t2;
		f1=f2=false;
		for(int i=0;i<t1.size();i++){
			if(t1[i]=='a')d1[f1]++;
			else f1=true;
		}for(int i=0;i<t2.size();i++){
			if(t2[i]=='a')d2[f2]++;
			else f2=true;
		}int ans=0;
		for(int i=1;i<=n;i++){
			if(c1[i][0]<=d1[0]&&c1[i][1]<=d1[1]&&c2[i][0]+(d1[0]-c1[i][0])==d2[0]&&c2[i][1]+(d1[1]-c1[i][1])==d2[1])ans++;
		}cout<<ans<<'\n';
	}
	return 0;
}

