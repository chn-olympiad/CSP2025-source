#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,mc,an,am;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			r=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			mc=i;
			break;
		}
	}

	for(int i=1;i<=m+1;i++){
		if(i*n+1>mc){
		am=i;	
		cout<<am;
		  if(am%2==1){
			an=mc-(am-1)*n;
		  }else{
			an=n-(mc-(am-1)*n)+1;
		  }
		  break;
		}
	}
	cout<<" "<<an;
	return 0;
}
