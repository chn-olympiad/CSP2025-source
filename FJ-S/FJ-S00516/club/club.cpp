#include<bits/stdc++.h>
using namespace std;
int n,maxn;
struct asd{
	int a,b,c;
};
asd k[10001];
bool num[10001][4];
void check(){
	int maxv=0;
	for(int i=1;i<=n;i++){
		if(num[i][1]==true){
			maxv+=k[i].a;
		}
		if(num[i][2]==true){
			maxv+=k[i].b;
		}
		if(num[i][3]==true){
			maxv+=k[i].c;
		}
	}
	maxn=max(maxn,maxv);
	return ;
}
void dfs(int m,int a,int b,int c){
	if(m==n+1){
		check();
		return;
	}
	if(a<n/2){
		num[m][1]=true;
		dfs(m+1,a+1,b,c);
		num[m][1]=false;
	}
	if(b<n/2){
		num[m][2]=true;
		dfs(m+1,a,b+1,c);
		num[m][2]=false;
	}
	if(c<n/2){
		num[m][3]=true;
		dfs(m+1,a,b,c+1);
		num[m][3]=false;
	}
	return;
}
bool cmp(asd a,asd b){
	return a.a<b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int qwe=1;qwe<=t;qwe++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>k[i].a>>k[i].b>>k[i].c;
		}
		if(n<=30){
			dfs(1,0,0,0);
			cout<<maxn<<endl;
		}
		else{
			sort(k+1,k+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				maxn+=k[i].a;
			}
		}
		maxn=0;
	}
	return 0;
}
