#include<bits/stdc++.h>
using namespace std;

struct suan{
	int c1,c2,c3;
};
suan s[100034];
int a;
int mx;
void dfs(int c1,int c2,int c3,int sc){
	if(c1 > a/2){
		return;
	}
	if(c2 > a/2){
		return;
	}
	if(c3 > a/2){
		return;
	}
	if(c1+c2+c3==a){
		mx = max(mx,sc);
		return;
	}
	
	dfs(c1+1,c2,c3,sc+s[c1+1+c2+c3].c1);
	dfs(c1,c2+1,c3,sc+s[c1+1+c2+c3].c2);
	dfs(c1,c2,c3+1,sc+s[c1+1+c2+c3].c3);
}
void sv(){
	memset(s,0,sizeof(s));
	mx = 0;
	cin>>a;
	for(int i = 1;i <= a;i++){
		cin>>s[i].c1>>s[i].c2>>s[i].c3;
	}
	dfs(0,0,0,0);
	cout<<mx<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int i = 1;i <= t;i++){
		sv();
	}
	return 0;
}
