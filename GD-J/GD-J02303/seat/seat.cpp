#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p=0,x,y;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i]==p){
			p=i;
			break;
		}
	}
	if(((p-1)/n)%2==0){
		x=((p-1)/n)+1;
		y=(p-1)%n+1;
	}else{
		x=((p-1)/n)+1;
		y=n-(p-((x-1)*n))+1;
	}
	cout<<x<<' '<<y;
}
