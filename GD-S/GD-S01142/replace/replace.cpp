#include <bits/stdc++.h>
using namespace std;

const int maxn=200010;
char s[maxn][3][maxn];
char ask[3][maxn];
int slen[maxn];
int n,p,tlen,ans;

void open(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}
void input(){
	scanf("%d %d",&n,&p);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin >> s1 >> s2;
		for(int i=0;i<(int)s1.size();i++){
			s[i][1][i+1]=s1[i];
		}
		for(int i=0;i<(int)s2.size();i++){
			s[i][2][i+1]=s2[i];
		}
		slen[i]=s1.size();
	}
}
void solve(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=tlen-slen[i]+1;j++){
			bool fg=1;
			for(int k=1;k<=slen[i];k++){
				if(s[i][1][k]!=ask[1][j+k-1]){
					fg=0;break;
				}
			}
			if(fg){
				for(int k=1;k<=slen[i];k++){
					ask[1][j+k-1]=s[i][2][k];
				}
				bool fg2=1;
				for(int k=1;k<=tlen;k++){
					if(ask[1][k]!=ask[2][k]){
						fg2=0;break;
					}
				}
				if(fg2){
					ans++;
				}
				for(int k=1;k<=slen[i];k++){
					ask[1][j+k-1]=s[i][1][k];
				}
			}
		}
	}
}
void output(){
	//printf("I don't know the answer ! Please don't ask me !");
	printf("%d\n",ans);
}
void LunAsk(){
	while(p--){
		string t1,t2;
		cin >> t1 >> t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
		}else{
			for(int i=0;i<(int)t1.size();i++){
				ask[1][i+1]=t1[i];
			}
			for(int i=0;i<(int)t2.size();i++){
				ask[2][i+1]=t2[i];
			}
			tlen=t1.size();
			solve();
			output();
		}
	}
}
int main(){
	//open();
	input();
	//close();
	return 0;
}

