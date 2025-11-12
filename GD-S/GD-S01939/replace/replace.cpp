#include<bits/stdc++.h>
#define ad(k) (k=-~k)
#define F(i,a,b) for(register int i=a;i<=b;i=-~i)
#define D(i,a,b) for(register int i=a;i>=b;i=~-i)
#define min(a,b) (a<b?a:b)
using namespace std;const int N=2e5+1;
int n,q;string s[N][3],t[N][3];
int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	cin>>n>>q;
	F(i,1,n)cin>>s[i][1]>>s[i][2];
	F(i,1,q){
		cin>>t[i][1]>>t[i][2];
		int l=-1,r=-1,cnt=0;
		F(j,0,t[i][1].size()-1){
			if(t[i][1][j]!=t[i][2][j]&&l==-1)l=j,r=-1;
			if(t[i][1][j]==t[i][2][j]&&l!=-1&&r==-1)r=j-1;
		}bool f=0;
		F(j,1,n){
			int k=t[i][2].find(s[j][2]),k1=t[i][1].find(s[j][1]);
			while(k!=-1){
				if(k+s[j][2].size()-1>=r&&k<=l&&k1==k)cnt++;
				k=t[i][2].find(s[j][2],k+1),k1=t[i][1].find(s[j][1],k1+1);
				if(k>l||k1>l)break;
			}
		}cout<<cnt<<endl;
	}
	return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
*/
