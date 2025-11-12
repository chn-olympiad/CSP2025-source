#include<bits/stdc++.h>
using namespace std;
int seat[15][15];
int ch[110],n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>ch[i];
	}
	int a=ch[1];
	sort(ch+1,ch+1+n*m,cmp);
	int w;
	for(int i=1;i<=n*m;i++){
		if(ch[i]==a){
			w=i;
		}
	}
	int c;
	if(w%n==0){
		c=w/n;
	}
	int r;
	if(c%2){
		r=w%n;
	}
	else {
		r=n-w%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
