#include <bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			f=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			f=i;
			break;
		}
	}
	
	int x=f%(2*m)/(m+1)+1+f/(2*m)*2,y;
	if(x%2==0){
		y=m-f%(2*m)%(m+1);
	}else{
		y=f%(2*m)%(m+1);
	}
	cout<<x<<" "<<y;
	return 0;
}
