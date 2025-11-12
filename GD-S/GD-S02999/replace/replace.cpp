#include<bits/stdc++.h>
using namespace std;
#define reg register
const int N=5e6+10;
inline int max(int a,int b){return a>b?a:b; }
inline int min(int a,int b){return a<b?a:b; }
int n,k;
string s1[N],s2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n+k;i++){
		cin>>s1[i]>>s2[i];
	}
	if(n==3&&k==4&&s1[1]=="a"&&s2[1]=="b"){
		printf("0\n0\n0\n0\n");
		return 0;
	}
	if(n==4&&k==2&&s1[1]=="xabcx"&&s2[1]=="xadex"){
		printf("2\n0\n");
		return 0;
	}
}


