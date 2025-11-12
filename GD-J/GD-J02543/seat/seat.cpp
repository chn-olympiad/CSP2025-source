#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N+1],xrcj;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	int zs=n*m;
	for(int i=1;i<=zs;i++){
		cin>>a[i];
		if(i==1)xrcj=a[i];
	}
	sort(a+1,a+zs+1,cmp);
	int index;
	for(int i=1;i<=zs;i++){
		if(a[i]==xrcj){
			index=i;
			break;
		}
	}
	int szl,szh;
	if(index%n==0)szl=index/n;
	else szl=index/n+1;
	if(szl%2==1){
		if(index%n==0)szh=n;
		else szh=index%n;
	}
	else{
		szh=n-index%n+1;
	}
	cout<<szl<<' '<<szh;
	return 0;
} 
