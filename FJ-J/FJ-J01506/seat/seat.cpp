#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xx=a[1];
	sort(a+1,a+n+1,cmp);
	int nn=0,mm=1;
	bool p=0;
	for(int i=1;i<=n*m;i++){
		if(p==0) nn+=1;
		else nn-=1;
		if(nn==n+1){
			nn=n;
			mm+=1;
			p=1;
		}else if(nn==0){
			nn=1;
			mm+=1;
			p=0;
		}
		if(a[i]==xx){
			cout<<mm<<" "<<nn;
			return 0; 
		}
	}
	return 0;
}
