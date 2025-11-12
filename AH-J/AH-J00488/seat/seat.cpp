#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l[110]={};
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>l[i];
	}int rs=l[0];
	sort(l,l+n*m,cmp);
	int lf=0,r=m*n-1,mid;
	while(1){
		mid=(lf+r)/2;
		if(rs>l[mid])r=mid;
		if(rs<l[mid])lf=mid;
		if(rs==l[mid]){
			break;
		}
	}rs=mid;
	int col,row;
	col=rs/n+1;
	if(col%2)row=rs%n+1;
	else row=n-(rs%n);
	cout<<col<<' '<<row;
}
