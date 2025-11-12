#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[15][15];
int a[105];
int mc,id=0,cd,mcp,mo,no;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	mc=a[1];
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		id++;
		if (a[i]==mc){
			mcp=n*m-id+1;
		}
	}
	mo=mcp/n+mcp%n;
	if (mo%2==1){
		if(mcp%n==0){
			no=n;
		}else{
			no=mcp%n;
		}
	}else{
		no=n-m%n;
	}
	cout<<mo<<" "<<no;
	return 0;
}
