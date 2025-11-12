#include<bits/stdc++.h>
using namespace std;
int x,y,i,s[1001],n,m,r,ri;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>s[i];
	}
	r=s[1];
	sort(s+1,s+n*m+1,cmp);
	i=0;
	while(s[++i]!=r){}
	ri=i;
//	for(i=1;i<=n*m;i++){
//		if(s[i]==r){
//			ri=i;
//		}
//	}
	x=(ri-1)/n+1;
	y=(x%2?ri-(x-1)*n:n-(ri-(x-1)*n)+1);
	cout<<x<<" "<<y;
	return 0;
}
