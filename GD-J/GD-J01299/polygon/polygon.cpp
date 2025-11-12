#include<bits/stdc++.h>
using namespace std;
int n,m=0,a[5010],x;
long long s,y;
void dfs(int k,int l){
	if(k==x+1&&s*2<y){
		m++;
		m%=244;
		return;
	}
	for(int i=l+1;i<=n;i++){
		if(a[i]!=-1){
			long long f=a[i],d=s;
			a[i]=-1;
			y+=f;
			s=max(s,f);
			dfs(k+1,i);
			a[i]=f;
			y-=f;
			s=d;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		x=i;
		s=-1;
		y=0;
		dfs(1,0);
	}
	cout<<m;
	return 0;
}
