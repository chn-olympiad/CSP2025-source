#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b) {return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10001],mysc,s=1,y=1,x=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	mysc=a[1];
	sort(a+1,a+n*m+1,cmp);
	while(a[s]!=mysc){
		if(x&1){
			y++;
		}
		else{
			y--;
		}
		if(y>n){ 
			x++;
			y--;
		}
		if(y<1){ 
			x++;
			y=1;
		}
		s++;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
//100 99 98 97 96 95 94 93 92

