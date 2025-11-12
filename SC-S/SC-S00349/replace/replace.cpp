#include<bits/stdc++.h>
using namespace std;
int q,n,ans;
string s1,s2,qq;
int c[101010];
int shu[510000][100];
int chang[51000];
int qchang[51000]; 
int qshu[510000][100];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		chang[i]=s1.size();
		for(int j='a';j<='z';j++){
			for(int w=1;w<=n;w++){
				if(s1[w]==j){
					shu[i][j]++;			
				}
				if(s2[w]==j){
					shu[i][j]++;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qq;
		qchang[i]=qq.size();
		for(int j='a';j<='z';j++){
			for(int w=1;w<=qchang[i];w++){
				if(qq[w]==j){
					qshu[i][j]++;			
				}
			}
		}
	}
	ans=0;
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			for(int w='a';w<='z';w++){	
				if(qshu[i][w]>shu[n][w]){
					break;
				}
				if(w=='z'){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl; 
	return 0;
}