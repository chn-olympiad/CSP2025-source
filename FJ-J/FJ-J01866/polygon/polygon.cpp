#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0,N=996244353; 
inline int fr(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
	   	x=(x*10)+(ch-'0');
		ch=getchar();
   }
	return x*f;
}
bool cmp(int x,int y){
	return x>y;
}
int C(int n,int m){
	int a=1,b=1,nn=n,mm=m;
	for(int i=1;i<=n;i++){
		a*=nn;
		b*=mm;
		nn--;
		mm--;
	}
	return b/a;
}
int cc(int x){
	int ss=0;
	for(int i=0;i<=x;i++){
		ss+=C(i,x);
		ss%=N;
	}
	return ss;
}
struct asd{
	int l,s,t;
};
queue<asd> q;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=fr();
	for(int i=1;i<=n;i++) a[i]=fr();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n-1;i++){
		q.push({i,a[i],1});	
	}
	while(!q.empty()){
		asd u=q.front();
		q.pop();
		if(u.t>=3&&u.s<0){
			ans+=cc(n-u.l);
			ans%=N;
			continue;
		}
		for(int i=u.l+1;i<=n;i++){
			q.push({i,u.s-a[i],u.t+1});
		}
	}
	cout<<ans;
	return 0;
}
