#include<bits/stdc++.h>
using namespace std;
int n,m,rec,lv,st;
int x,y;
int mark[120];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>mark[i];
	rec=mark[1];
	sort(mark+1,mark+1+n*m);
	for(int i=1;i<=n*m;i++)
		if(mark[i]==rec){
			lv=n*m-i+1;
			break;
		} 
	if(lv%n){
		x=lv/n+1;
		if((lv/n+1)%2) y=lv%n;
		else y=n-(lv%n)+1;
	}else{
		x=lv/n;
		if((lv/n)%2) y=n;
		else y=1;
	}
	cout<<x<<" "<<y;
	return 0;
}
