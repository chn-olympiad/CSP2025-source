#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a,d[100010],ans;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++){
			cin>>a>>d[i]>>a;
			
		}
		sort(d+1,d+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=d[i];
		}
		cout<<ans;
	}
	return 0;
}
