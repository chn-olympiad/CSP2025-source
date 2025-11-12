#include<iostream>
#include<algorithm>
using namespace std;
int l[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=0,y=0;
	bool d=1;
	cin>>n>>m;
	cin>>l[0];
	int grade=l[0],j=0;
	for(int i=1;i<n*m;i++) cin>>l[i];
	sort(l,l+n*m);
	for(int i=n*m-1;i>=0;i--,j++)
		if(l[i]==grade)
			break;
	for(int i=1;i<=j;i++){
		if(d==0) x--;
		else x++;
		if(x>=n){d=!d;x--;y++;}
		else if(x<0){d=!d;x++;y++;}
	}
	cout<<y+1<<' '<<x+1;
}
