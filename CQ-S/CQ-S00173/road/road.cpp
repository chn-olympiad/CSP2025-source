#include<bits/stdc++.h> 
using namespace std;
struct xxs{
	int a,b,c;
}q[1000005];
int n,m,k,ans=0,x[1000][1000],cnt=0;
bool cmp(xxs a22,xxs b43){
	return a22.c<=b43.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>q[i].a>>q[i].b>>q[i].c;
	ans=m;
	for(int i=1;i<=k;i++){
		int a1,a2[10004];
		cin>>a1;
		for(int j=1;j<=n;j++){
			cin>>a2[j];
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans++;
				q[ans].a=i;
				q[ans].b=j;
				q[ans].c=a1+a2[i]+a2[j];
			}
		}
	}
	sort(q+1,q+ans+1,cmp);
	for(int i=1;i<=n-1;i++) cnt+=q[i].c;
	cout<<cnt;
	return 0;
}
