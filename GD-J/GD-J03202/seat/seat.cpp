#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int a1;
int x=1,y=1;
bool cmp(const int&l,const int&k){
	return l>k;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	a1=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			cout<<x<<' '<<y;
			break;
		}
		if(x%2!=0){
			if(y==n)x++;
			else y++;
		}else{
			if(y==1)x++;
			else y--;
		}
	}
	return 0;
}
