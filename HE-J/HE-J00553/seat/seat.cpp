#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],k,r;
bool cmp(int b,int c){
	return b>c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(r==a[i]){
			r=i;
			break;
		}
	}
	if(r%m==0){
		cout<<r/m<<' '<<m;
	}
	else{
		cout<<r/m+1<<' ';
		if((r/m+1)%2==0){
			cout<<m-r%m+1;
		}
		else{
			cout<<r%m; 
		}
	}
	return 0;
}

