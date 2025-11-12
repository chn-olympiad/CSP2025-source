#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m,l;
int x=1,y=1;
int tgt,ord;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	l=n*m;
	cin>>a[0];
	tgt=a[0];
	for(int i=1;i<l;i++){
		cin>>a[i];
	}
	sort(a,a+l,cmp);
	for(int i=0;i<l;i++){
		if(a[i]==tgt){
			ord=i;
			break;
		}
	}
	for(int i=0;i<ord;i++){
		if(x%2==0)y--;
		else      y++;
		if(y>n){
			x++;
			y--;
		}
		if(y<1){
			x++;
			y++;
		}	
	}
	cout<<x<<' '<<y;
	return 0;
}
