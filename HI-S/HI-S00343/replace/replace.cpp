#include<bits/stdc++.h>
using namespace std;
const int MAXN=200010;
string s[MAXN][5],q[MAXN][5];
int n,p,ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=p;i++){
		cin>>q[i][1]>>q[i][2];
	}
	int len1,len2;
	int st;
	bool A;
	string g;	
	for(int i=1;i<=p;i++){
		ans=0;
		len2=q[i][1].length();
		for(int j=1;j<=n;j++){
			g=q[i][1];
			len1=s[j][1].length();
			st=q[i][1].find(s[j][1]);
			if(st==-1) continue;
			else{
				printf("%d,%d\n",i,j);
				int k=st,z=0;
				for(;z<len1;k++,z++){
					g[k]=s[j][2][z];
				}
				cout<<g<<endl;
				if(g==q[i][2]){
					ans++;	
					for(z=0;k<=len2-len1;k++){
		     			if(g[k]==s[j][2][0]){
			    			A=0;
		     				g=q[i][1];
				   	    	for(;z<len1;z++,k++){
					    		if(g[k]!=s[j][2][z]){
					    			A=1;
					    			break;
				     			}
				     		}
						    if(!A){
						    	ans++;
						    }
						    z=0;
						}
					}				
				}else continue;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 2
a a
b b
*/
