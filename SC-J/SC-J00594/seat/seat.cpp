#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int a1;
int p=1,q=1,j=1;
bool fg=false;
bool cmp(int a,int b){
	return a>b;
}
bool check(){
	if(a[j]==a1){
		cout<<p<<" "<<q;
		return true;	
	}
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	while(1){
		if(check())break;
	 	if(q==1){
	 		if(fg){
	 			p++,j++,fg=false;
	 			if(check())break;
	 			continue;
			 }
		}
		if(q==n){
			if(!fg){
				p++,j++;
				fg=true;
				if(check())break;
				continue;
			}
		}
		if(!fg)q++;
		else q--;
		j++;
	}
}