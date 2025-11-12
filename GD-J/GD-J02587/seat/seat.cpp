#include<bits/stdc++.h> 
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[100001];
int ans;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num)ans=i;
	}
	if(((ans-1)/n)%2==0){
		printf("%d %d",ans/n+(ans%n?1:0),(ans-1)%n+1);
	}else{
		printf("%d %d",ans/n+(ans%n?1:0),n-((ans-1)%n+1)+1);
	}
	return 0;
}
