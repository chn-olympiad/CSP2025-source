#include <iostream>
#include <algorithm>
using namespace std;
const int N=1000+10;
int n,m;
int a[N];
bool cmp(int a,int b){
	return b<a;
}
int main(){ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int A=a[1];
	sort(a+1,a+1+n*m,cmp);
	int index;
	for(int i=1;i<=n*m;i++){
		if(a[i]==A){
			index=i;
		}
	}

	int x,y;
	if(index%n!=0){
		x=index/n+1;
		if(x%2==0){
			y=m-index%n+1;
		}else{
			y=index%n;
		}
	}else{
		x=index/n;
		if(x%2==0){
			y=1;
		}else{
			y=n;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}