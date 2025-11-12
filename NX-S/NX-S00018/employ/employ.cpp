#include <bits/stdc++.h>
using namespace std;
int a1[1000000];
int b1[1000000];
int c1[1000000];
int js=0;
int n,m,ren=0;
void DFS(int fl,int emp){
	if(fl>n){
		if(ren>=m){
			js++;
			cout<<endl;
		}
		return;
		}
	for(int i=1;i<=n;i++){
		if(b1[i]>emp and a1[fl]==1 and c1[i]==0){
			ren++;
			c1[i]=1;
			DFS(fl+1,emp);
			c1[i]=0;
			ren--;
		}
		else if(c1[i]==0){
			c1[i]=1;
			DFS(fl+1,emp+1);
			c1[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char a;
		cin>>a;
		a1[i]=a-48;
	}
	for(int i=1;i<=n;i++){
		cin>>b1[i];
	}
	DFS(1,0);
	cout<<js;
	return 0;}
	
