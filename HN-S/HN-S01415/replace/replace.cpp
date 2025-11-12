#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q;
string s[maxn];
int w1[maxn];
int w2[maxn];
string s1[maxn];
bool vis[maxn];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
		for(int j=0;j<max(s[i].size(),s1[i].size());j++){
			if(s[i].size()>j){
				if(s[i][j]=='b'){
					if(w1[i]!=0){
						vis[i]=false;
						break;
					}else{
						w1[i]=j;
					}
				}
			}
			if(s1[i].size()>j){
				if(s1[i][j]=='b'){
					if(w2[i]!=0){
						vis[i]=false;
						break;
					}else{
						w2[i]=j;
					}
				}
			}
		}
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int wei1=0,wei2=0;;
		for(int i=0;i<a.size();i++){
			if(a[i]=='b'){
				wei1=i;
				break;
			}
		}
		for(int i=0;i<b.size();i++){
			if(b[i]=='b'){
				wei2=i;
				break;
			}
		}
		long long num=0;
		if(wei1==wei2){
			num++;
		}
		for(int i=1;i<=n;i++){
			if((w2[i]<=wei2)&&((s1[i].size()-w2[i])<=(b.size()-wei2))&&(w1[i]<=wei1)&&((s[i].size()-w1[i])<=(a.size()-wei1))&&(wei1-w1[i]+w2[i]==wei2)){
				num++;
			}else if((w1[i]<=wei2)&&((s[i].size()-w1[i])<=(b.size()-wei2))&&(w2[i]<=wei1)&&((s1[i].size()-w2[i])<=(a.size()-wei1))&&(wei1-w2[i]+w1[i]==wei2)){
				num++;
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
