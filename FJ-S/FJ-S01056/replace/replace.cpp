#include<bits/stdc++.h>
using namespace std;
const int N=2e3+20;
int n,q;
string s1[N],s2[N],t1,t2;
int siz[N],nxt[N][N],ans;
int main(){
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		siz[i]=s1[i].size();
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		int tiz=t1.size();
		int sm1=1,sm2=tiz;
		while(t1[sm1]==t2[sm1]&&sm1<=n)sm1++;sm1--;
		while(t1[sm2]==t2[sm2]&&sm2)sm2--;sm2++;
		for(int k=1;k<=n;k++)
		for(int i=0,j;i+siz[k]-1<tiz;i++){
			for(j=0;j<siz[k];j++)
				if(t1[i+j]!=s1[k][j])break;
			if(j==siz[k]){
				for(j=0;j<siz[k];j++)
					if(t2[i+j]!=s2[k][j])break;
				if(j==siz[k]&&i+j-1<sm2-1)ans++;
			}
			if(i>sm1)break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

