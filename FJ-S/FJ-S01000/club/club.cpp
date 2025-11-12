#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100001][4],cnt,df[100001][4];
void dfs(long long t,long long x,long long y,long long z,long long ctt,long long lj){
	cnt=max(cnt,ctt);
//	if(t!=1){
//		if(ctt<df[t][lj]){
//		//cout<<"tiao过！"<<endl; 
//		return;
//	}else{
//		df[t][lj]=ctt;
//	}

//	}
	if(t>n||(x==0&&y==0&&z==0)){
		return;
	}
	if(x!=0){
	//	cout<<"招聘了"<<t<<"号同学，他进入了"<<1<<"部门,满意度增加"<<a[t][1]<<"度，当前满意度："<<ctt+a[t][1]<<endl;
		long long rctt=ctt+a[t][1];
		dfs(t+1,x-1,y,z,rctt,1);
	}
	if(y!=0){
	//	cout<<"招聘了"<<t<<"号同学，他进入了"<<2<<"部门,满意度增加"<<a[t][2]<<"度，当前满意度："<<ctt+a[t][2]<<endl;
		long long rctt=ctt+a[t][2];
		dfs(t+1,x,y-1,z,rctt,2);
	}
	if(z!=0){
	//	cout<<"招聘了"<<t<<"号同学，他进入了"<<3<<"部门,满意度增加"<<a[t][3]<<"度，当前满意度："<<ctt+a[t][3]<<endl;
		long long rctt=ctt+a[t][3];
		dfs(t+1,x,y,z-1,rctt,3);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
	scanf("%lld",&n);
	cnt=0;
	memset(df,0,sizeof(df));
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
	}
	dfs(1,n/2,n/2,n/2,0,0);
	printf("%lld\n",cnt);
}
	return 0;
}




