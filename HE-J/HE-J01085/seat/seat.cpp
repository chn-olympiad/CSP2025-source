#include <bits/stdc++.h>
using namespace std;
int n,m,nm,r,a[1010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+1+nm,cmp);
	for(int i=1;i<=nm;i++){
		if(a[i]==r){
			int y=(i-1)/n+1,x;
			if(y%2==1)x=(i-1)%n+1;
			else x=n-((i-1)%n+1)+1;
			printf("%d %d",y,x);
			return 0;
		}
	}
	return 0;
} 
