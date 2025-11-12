#include<iostream>
#include<algorithm>
using namespace std;
int n,m,sc,c=1,r=1;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sc=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sc){
			cout<<c<<' '<<r;
			break;
		}
		if(c%2==1)r++;
		else r--;
		if(r>n)r=n,c++;
		if(r<1)r=1,c++;
	}
	return 0;
}
