/* UNDEBUGGED */
/* REDIRECTED */ 
/* ACTUALLY I DONT REALLY CARE
  'CAUSE DIS WAS TOO HARD     */

#include<iostream>
#include<cstring>
#include<cstdio>
//#define debug CERTAINLY
using namespace std;

/* Nyaaaa~ 
   stikzzz */
const int MAXN=5e3;
size_t n;
int stikz[MAXN+5];
int chooz[MAXN+5];

void dfs(int cnt,int chozen){
	if(chozen==cnt){
		for(size_t i=0;i<cnt;++i)cout<<chooz[i]<<' ';
		cout<<'\n'; 
		return;
	}
	
	for(size_t i=chozen;i<cnt;++i){
		++chozen;
		chooz[chozen]=stikz[i];
		dfs(cnt,chozen);
		--chozen;
	}
}

int main(){
	//optimise i/o
	cin.tie(nullptr);
	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
	//redirect i/o
	freopen("polygon.in","r",stdin);
	#ifndef debug
	freopen("polygon.out","w",stdout);
	#endif
	
	cin>>n;
	for(size_t i=0;i<n;++i)cin>>stikz[i];
	// 
	dfs(3,0);
	
    return 0;
}

