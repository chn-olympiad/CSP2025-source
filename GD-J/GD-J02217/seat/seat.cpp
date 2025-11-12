#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int b[100010];
int s=1,x=1,y=1,sum,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	sum=b[1];
	sort(b+1,b+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(b[i]==sum){
			num=n*m-i+1;
			break;
		}
	}
	while(x<=n){
		if(s==num){
			if(x==1) cout<<y<<" "<<x;
			else cout<<y-2<<" "<<x;
		}
		if(y%2==1){
			s+=2*(n-x+1)-1;
		}
		if(y%2==0){
			s+=2*(x-1)+1;
		}
		
		
		if(y>=m and x==1 or x>=2 and y>=m+2){
			y=2,x++,s=x;
		}
		y++;
	}
	return 0;
}
//1 8 9  16 17
//2 7 10 15 18
//3 6 11 14 19
//4 5 12 13 20
