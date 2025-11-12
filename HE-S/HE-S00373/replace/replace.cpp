#include<bits/stdc++.h>
using namespace std;
int n,q;
int ans;
int t;
char op[10010][3][10010];
char que[10010][3][10010]; 
int f[10010][10010];
int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>op[i][1]+1;
		cin>>op[i][2]+1;
	}
	for(int i=1;i<=q;++i){
		cin>>que[i][1]+1;
		cin>>que[i][2]+1;
		int tlen=strlen(que[i][1]+1);
		ans=0;
		for(int j=1;j<=n;++j){
			for(int k=1;k<=strlen(op[i][1]+1);++k){
				t=0;
				for(int ii=k;ii<=k+tlen;++ii){
					if(op[i][1][ii]!=que[i][1][ii-k+1]||op[i][2][ii]!=que[i][2][ii-k+1]||f[i][ii]==1){
						t=1;
						break;
					}
				}
				if(t==0){
					for(int ii=k;ii<=k+tlen-1;++ii){
						f[i][ii]=1;
					}
					ans++;
				}
				
			}
		}
		cout<<ans<<endl;
	}
	/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a


4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
	*/
	return 0;
}
