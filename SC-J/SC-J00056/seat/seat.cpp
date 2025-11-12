#include<bits/stdc++.h>
using namespace std;
const int N=200;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m,cmp);
	int i=1,x=1,y=1,flag=1;
	while(a[i]!=t){
		i++;
		if(flag==1){
			if(x==n){
				y++;
				flag=2;
			}
			else x++;
		}else {
			if(x==1){
				flag=1;
				y++;
			}
			else x--;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}