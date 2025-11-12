#include<bits/stdc++.h>
using namespace std;
bool book[10001];int a[10001],n,f[10001][10001],fl=1;
bool qc(){
	bool re=true,e[fl];
	if(fl==1){
		return true;
	}
	for(int j=1;j<fl;j++){
		e[j]=false;
	}
	for(int i=1;i<fl;i++){
		int su=0,sa=0;
		for(int j=1;j<=n;j++){
			if(f[i][j]==1){
				su++;
			}if(book[j]){
				sa++;
			}
			if(f[i][j]==0 && book[j]){
				e[i]=true;
			}
		}if(sa!=su){
			e[i]=true;
		}
	}for(int j=1;j<fl;j++){
		if(!e[j]){
			re=false;
		}
	}
	return re;
}
bool dbx(){
	int summ=0,maxx=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(book[i]){
			cnt++;
			summ+=a[i];
			maxx=max(a[i],maxx);
		}
	}
	if(summ>maxx*2 && cnt>=3 && qc()){
		for(int i=1;i<=n;i++){
			if(book[i]){
				f[fl][i]=1;
			}else{
				f[fl][i]=0;
			}
		}fl++;
		return true;
	}
	return false;
	
}
int dfs(int s){
	int summ=0;
	if(s>n){
		return 0;
	}else if(dbx()){
		summ++;
	}
	for(int i=1;i<=n;i++){
		if(!book[i]){
			book[i]=true;
			summ+=dfs(s+1);
			book[i]=false;
		}
	}return summ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		book[i]=false;
	}
	cnt=dfs(1);
	for(int i=1;i<=n;i++){
		book[i]=true;
	}if(dbx){
		cnt++;
	}
	cout<<cnt%998%244%353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
