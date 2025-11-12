#include<bits/stdc++.h>
using namespace std;
int n,m,s,an,cn,anx,any;
int a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	an=a[1];
	sort(a+1,a+1+s,greater<int>());
	for(int i=1;i<=s;i++){
		if(a[i]==an){
			cn=i;
			break;
		}
	}
	anx=cn/n;
	if(cn%n)anx++;
	any=cn-cn/n*n;
	if(cn%n==0)any=n;
	if(anx%2==0)
		any=n+1-any;
	cout<<anx<<' '<<any;
	return 0;
} 
