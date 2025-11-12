//CSP-S00458 贵阳1市第三实验中学 陈则睿
//hyw?
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
bool s[100];
int c[100];
bool used[100];
int aa[100],ans=0;
void dfs(int x){
	if(x==n){
		int kill=0,anss=0;
		for(int i=0;i<n;i++){
			if(c[aa[i]]>kill){
				if(s[i]==0){kill++;}
				if(s[i]==1){anss++;}
			}
		}
		if(anss>=m){ans++;}
	}
	for(int i=0;i<n;i++){
		if(!used[i]){
			aa[x]=i;
			used[i]=1;
			dfs(x+1);
			used[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++){
		char cc=getchar();
		if(cc=='0')s[i]=0;
		if(cc=='1')s[i]=1;
	}
	for(int i=0;i<n;i++){cin>>c[i];}
	dfs(0);
	cout<<ans;
	return 0;
} 
