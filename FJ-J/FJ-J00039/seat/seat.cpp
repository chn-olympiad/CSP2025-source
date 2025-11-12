#include<bits/stdc++.h>
using namespace std;
int n,m,s[105],c,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int x=s[1],ind=1;
	sort(s+1,s+n*m+1,cmp);
	while(s[ind]!=x) ind++;
	c=(ind-1)/m+1;
	if(c%2){
		r=ind-(c-1)*m;
	}else{
		r=c*m-ind+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
