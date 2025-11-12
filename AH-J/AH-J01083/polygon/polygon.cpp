#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,a[5005],f[5005];
int mx=0;
long long cnt;
bool pd(int sum,int mx){
	if(sum>mx*2) return true;
	return false;
}
void dfs(int x,int sum,int mx,int step){
	mx=max(mx,a[x]);
	if(step>=3){
		if(pd(a[x]+sum,mx)){
			cnt++;
			cnt%=998244353;
		}
		sum+=a[x];
		//cout<<sum<<endl;
	}else{
		sum+=a[x];
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,sum,mx,step+1);
	}
}
void dfs1(int x,int sum){
	if(sum==3){
		cnt+=f[n]-f[x]+1;
		//cout<<x<<" "<<cnt<<endl;
		cnt%=998244353;
		return ;
	}
	for(int i=x+1;i<=n;i++){
		dfs1(i,sum+a[i]);
	}
}
void bl(){
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(a[i]==1){
			f[i]++;
		}
		//cout<<f[i]<<" ";
	}
	//cout<<endl;
	for(int i=1;i<=n-2;i++){
		dfs1(i,a[i]);
	}
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx!=1&&n<500){
		sort(a+1,a+n+1);
		for(int i=1;i<=n-2;i++){
			dfs(i,0,0,1);
		}
		cout<<cnt;
	}else if(mx<=1){
		bl();
		cout<<cnt;
	}else{
		cout<<0;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
let me look this
emmm,maybe can use dfs  
but it will only get 24 
.......
???  why wrong
aaaaa
why why why??????????????
oh,the first data is 1,not 2
ye!,24 is in my hand
i write a te shu yang li,maybe can 48

lao tian bao you wo!!!!










*/
