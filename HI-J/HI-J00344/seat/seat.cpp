#include<bits/stdc++.h>
using namespace std;
struct P{
	int s;
}a[105];
bool com(const P&a,const P&b){
	return a.s>b.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y;
	cin>>n>>m;
	//int a[n*m+5];
	for(int i=0;i<n*m;i++) cin>>a[i].s;
	x=a[0].s;
	sort(a,a+n*m-1,com);
	for(int i=0;i<n*m;i++){
		if(a[i].s==x){
			y=i+1;
			break;
		}
	}
	//cout<<y<<endl;
	if(y<=n) cout<<"1 "<<y;
	else if(n==2) cout<<"2 "<<-(n-y-1);
	else{
		cout<<y/n+1<<' ';
		if((y/n)%2==0) cout<<n-y%(n+1)+1;
		else cout<<y%(n+1);
    }
	return 0;
}
