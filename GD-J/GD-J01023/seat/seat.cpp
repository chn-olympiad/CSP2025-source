#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],x=1,y=1,d[2]={1,-1},l=0,cnt;
bool f=1;
bool cmp(int q,int p){
	return q>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	cnt=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			cout<<y<<' '<<x;
			break;
		}
		if((x==n||x==1)&&f==0) y++,l=1-l,f=1;
		else x+=d[l],f=0;
	}
	return 0;
} 
