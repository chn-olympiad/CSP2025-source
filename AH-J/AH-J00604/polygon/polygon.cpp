#include<bits/stdc++.h>
using namespace std;
int way;
int n,a[1000005];
void bigin(int id,bool flag,int num,int maxx,int sum){
	if(flag){
		num+=a[id];
		maxx=max(maxx,a[id]);
		sum++;
	}
	if(id>n||sum>n){
		return;
	}
	if(num>maxx*2){
		way++;
	}
	if(flag&&id+1==n){
		bigin(id+1,1,num,maxx,sum);
		return;
	}
	if(num>maxx*2){
		bigin(id+1,1,num,maxx,sum);
		return;
	}
	bigin(id+1,1,num,maxx,sum);
	bigin(id+1,0,num,maxx,sum);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bigin(1,1,0,0,0);
	bigin(1,0,0,0,0);
	cout<<way%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
