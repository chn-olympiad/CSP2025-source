#include<bits/stdc++.h>
#define uint unsigned long long
using namespace std;
int n,q;
const uint b=233;
char s[(int)2e6+10],t[(int)2e6+10];
uint h1[(int)2e6+10],h2[(int)2e6+10];
uint H1[(int)2e6+10],H2[(int)2e6+10];
char S[(int)2e6+10],T[(int)2e6+10];int len[(int)2e6+10];
uint B[(int)2e6+10];
vector<pair<int,int> >v[(int)2e6+10];
uint Hash(int id,int l,int r){
	if(id==1)return (H1[r]-H1[l-1])*B[(int)2e6-r];
	else return (H2[r]-H2[l-1])*B[(int)2e6-r];
}
int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	cin>>n>>q;B[0]=1;
	if(n*q>=1e7){for(int i=1;i<=q;i++)puts("0");return 0;}
	for(int i=1;i<=2e6;i++)B[i]=B[i-1]*b;
	for(int i=1;i<=n;i++){
		scanf("%s%s",s+1,t+1);
		int L=strlen(s+1);
		for(int j=1;j<=L;j++){
			h1[i]+=s[j]*B[j];
			h2[i]+=t[j]*B[j];
		}h1[i]*=B[(int)2e6-L],h2[i]*=B[(int)2e6-L];
		len[i]=L;
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",S+1,T+1);
		int L=strlen(S+1);
		for(int j=1;j<=L;j++){
			H1[j]=H1[j-1]+S[j]*B[j];
			H2[j]=H2[j-1]+T[j]*B[j];
		}int ans=0;
		for(int j=1;j<=n;j++){
			if(len[j]>L)continue;
			for(int k=1;k<=L-len[j]+1;k++){
				if(h1[j]==Hash(1,k,k+len[j]-1)&&
				h2[j]==Hash(2,k,k+len[j]-1)&&
				Hash(1,1,k-1)==Hash(2,1,k-1)&&Hash(1,k+len[j],L)==Hash(2,k+len[j],L))
				ans++;
			}
		}cout<<ans<<'\n';
	}
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
/*
3 4
a b 
b c
c d
aa bb
aa b
a c
b a
*/
