#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=200010;
string l[N],w[N];
int n,q;
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&w[i]);
	}for(int i=1;i<=q;i++){
		int cnt=0;
		scanf("%d%d",&t1,&t2);	
		cin>>t1>>t2;
		int len=t1.size();
		for(int i=1;i<=n;i++){
			string x="",z="";
			int lel=l[i].size();
			int s;
			for(int j=0;j<=len-lel;j++){
				int o=1;
				s=j;
				for(int k=0;k<lel;k++){
					if(l[i][k]!=t1[j+k]){
						o=0;
						break;
					}
				}if(o){
					for(int j=0;j<s;j++)x+=t1[j];
					for(int j=s+lel;j<len;j++)z+=t1[j];
					if(x+w[i]+z==t2){
						cnt++;
					}
					break;
				}
			}
		}printf("%d",cnt);
	}
	return 0;
}

