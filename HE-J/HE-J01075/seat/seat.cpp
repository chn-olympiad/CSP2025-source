#include<iostream>
#include<algorithm>
using namespace std;
int n,m,me=0;
int a[20];
bool cmp(int x,int y){
	return x>y;
}
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	me=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==me){
			me=i;
		}
	}
	int j;
	if(me%n==0){
		j=me/n;
	}else{
		j=me/n+1;
	}
	int i;
	i=me%n;
	if(i==0){
		i=n;
	}
	if(j%2==0){
		i=n-i+1;
	}
	cout<<j<<" "<<i<<endl;
	return 0;
}
