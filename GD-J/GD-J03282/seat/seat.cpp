#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int R;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			R=i;
			break;
		}
	}
	//cout<<R<<endl;
	int h=ceil(R*1.0/n);
	int l; 
	bool flag=h%2;
	
	l=R%n;
	if(l==0) l=n;
	if(!flag){
		l=n-l+1;
	}		
	cout<<h<<' '<<l;
	return 0;
}
/*
2 2
 99 100 97 98
*/
