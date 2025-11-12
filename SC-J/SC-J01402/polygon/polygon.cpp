#include<bits/stdc++.h>
using namespace std;
int n,a[5001],now[5001],a1[5001];
map<long long,long long> sss;
long long ans=0,rt;
long long s1,ji=0;
const long long M=998244353;
long long wow(int x){
	long long s=1;
	for(int i=2;i<=x;i++){
		s=s*i;
	}
	return s;
}
long long ads(int a,int b){
	long long s=1;
	for(int i=1;i<=b;i++){
		s=s*a;
	}
	return s;
}
long long can(int m,int n){
	return wow(m)/(wow(n)*wow(m-n));
}
bool check(int n,int x){
	int s=0;
	for(int i=1;i<=n;i++){
		s=s+a[now[i]];
		if(s>x) return 0;
	}
	return 1;
}
void dfs(int m,int n,int x){
	//cout<<"now[]=";
	//for(int i=1;i<=n;i++){
	//	cout<<now[i]<<" ";
	//}
	//cout<<endl;
	long long hs=0;
	for(int i=1;i<=n;i++){
		hs=hs+now[i]*ads(n,i-1);
	}
	if(sss.find(hs)==sss.end() or sss[hs]!=ji){
		sss[hs]=ji;
	}else{
		return;
	}
	if(check(n,x)){
		s1--;
		//cout<<"s1--!!! s1="<<s1<<endl;
		//cout<<"n="<<n<<" m="<<m<<endl;
		for(int i=1;i<=n;i++){
			if(now[i]+1!=now[i+1] and now[i]+1<=m){
				//cout<<"It did!"<<" It's "<<i<<endl;
				now[i]++;
				dfs(m,n,x);
				now[i]--;
			}
		}
		return;
	}else{
		return;
	}
	return;
}
//m=前m个数，n=选n个数，x=要＞x 
long long solve(int m,int n,int x){
	ji++;
	s1=can(m,n)%M;
	//cout<<"s1="<<s1<<endl;
	memset(now,0,sizeof(now));
	for(int i=1;i<=n;i++){
		now[i]=i;
	}
	dfs(m,n,x);
	while(s1<0){
		s1+=M;
	}
	return s1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i-1]=a[i]-a[i-1];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=2;j<=i-1;j++){
			//cout<<"           i="<<i<<" j="<<j;
			rt=solve(i-1,j,a[i]);
			//cout<<"           solve="<<rt<<endl;
			ans=ans+rt;
			ans=ans%M;
		}
	}
	cout<<ans;
	return 0;
} 