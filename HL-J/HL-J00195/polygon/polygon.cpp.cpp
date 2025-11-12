#include<bits/stdc++.h>
using namespace std;
int a[5008];
int w[5008][655317];
int n;
bool check(int op){
	int sum=0;
	int maxx=0;
	for(int i=1;i<=n;i++){
		if((1<<i)&op){
			maxx=max(a[i],maxx);
			sum+=a[i];
		}
	}
	return sum>maxx*2;
}

int dfs(int x,int op){
	if(x==0){
		return check(op);
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(!((i<<i)&(op))){
			w[x][op]=dfs(x-1,op+(1<<i));
		}
		if(w[x][op]!=-1){
			res+=w[x][op];
		}
	}

	return res;
}
int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(n,0);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
