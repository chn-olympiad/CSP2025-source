#include <bits/stdc++.h>
using namespace std;
int a[100010],n,m,t,x,y;
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
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	x=0;//ÁÐ 
	y=0;//ÐÐ 
	for(int i=1;i<=n*m;i++){
		if(y==n||y==0){
			x++;
		}
		if(x%2!=0)y++;
		if(a[i]==t){
			cout<<x<<" "<<y;
			return 0;
		}
		if(x%2==0)y--;
		
	}
	return 0;
} 
