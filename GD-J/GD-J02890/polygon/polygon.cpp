//ad astra per aspera 
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
/* 
T4
我谢谢你 
还要写这个 
地哎付哎斯
调不动了 
寄 
*/ 
ll MOD=998244353;
ll n,f=0;
int gunmu[5005];//棍母棍母棍母棍母棍母
int ans[5005];

void dfs(int wm,int dx,int adx,int cen){//是的，乌蒙地插启动！ 
//	cout<<"wmdx: "<<wm<<" "<<dx<<" "<<adx<<" "<<cen<<endl;
	ans[cen]=wm;
	if(cen==adx){
		int mex=0,co=0;
		for(int i=0;i<adx;i++){
			mex=max(mex,gunmu[ans[i]]);//棍母棍母棍母棍母棍母
			co+=gunmu[ans[i]];//棍母棍母棍母棍母棍母
//			cout<<gunmu[ans[i]]<<" ";
		}
//		cout<<endl;
		if(mex*2<co){
			f++;
			f%=MOD;
		}
		return;
	}
	for(int i=wm;i<=wm+dx;i++){
		dfs(i+1,dx-1,adx,cen+1);
//		cout<<i<<endl; 
	}
	return;
} 
void init(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>gunmu[i];//棍母棍母棍母棍母棍母
	}
	for(int i=3;i<=n;i++){
		dfs(0,i,i,1);
	}
	cout<<f;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	init(); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*

神秘仪式 
int main(){
	int rp=1;
	while(1){
		rp++;
	}
	return 0;
}

*/