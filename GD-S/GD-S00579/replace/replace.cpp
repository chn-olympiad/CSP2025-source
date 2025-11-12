#include <bits/stdc++.h>
#define ll long long
#define FRE
using namespace std;
int read(){
	int t1=0,t2=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')t2=-1;
		c=getchar();
	}while(c>='0' && c<='9')t1=t1*10+c-'0',c=getchar();
	return t1*t2;
}
const int N=200050;
int n,q;
string s[N][3];
int main(){
	#ifdef FRE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>s[i][j];
		}
	} 
	for(int i=1;i<=q;i++){
		string t1,t2;cin>>t1>>t2;
		if(t1.length()!=t2.length()){cout<<0<<'\n';continue;}
		int len=t1.length();
		string be,end;
		bool flag=0;
		int l=0,r=len-1;
		for(;l<len;l++){
			if(flag){l--;break;}
			if(t1[l]!=t2[l]){
				for(;r>l;r--){
					if(t1[r]!=t2[r]){flag=1;break;}
				}
			}
		}
		cout<<0<<'\n';
	}
	return 0;
}

