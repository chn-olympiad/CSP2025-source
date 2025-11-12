#include<bits/stdc++.h>
using namespace std;
int sum,num,x,y,n,m,a[110];
bool cmp(int a,int b){
	if(a!=b) return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]>=sum) num++;
		else break;
	}
	for(int i=1;i<=n*m;i++){
		y++;
		if(y==m){
			x++;
			y=0;
		}
		if(y+x*m==num){
			if((x+1)%2==0){
				cout<<x+1<<' '<<m-y+1;
			}else {
				cout<<x+1<<' '<<y;
			}
		}
	}
return 0;
}
