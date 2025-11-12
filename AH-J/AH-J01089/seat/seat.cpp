#include<bits/stdc++.h>
using namespace std;
int a[105],s;
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,t;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		t=a[1];
	}
	
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==t){
			s=i;
			break;
		}
		
	}
	int r=s%m;
	if(r==0){
		cout<<s/m<<" ";
		if(s/m%2!=0)cout<<n;
		else cout<<1;
	}else{
		cout<<s/m+1<<" ";
		if((1+s/m)%2!=0)cout<<r;
		else cout<<n-r+1;
	}
	return 0;
}
