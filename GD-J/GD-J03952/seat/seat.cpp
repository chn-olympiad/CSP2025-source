#include<bits/stdc++.h>
using namespace std;
short n,m,h,l;
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num[n*m+1],r,wei;
	for(int i=1;i<=n*m;i++)cin>>num[i];
	r=num[1];
	sort(num+1,num+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(r==num[i])wei=i;
	for(int i=1;i<=m;i++){
		if(i*n>=wei&&(i-1)*n+1<=wei){
			h=i;
			break;
		}
	}
	for(int i=h*n;i>=(h-1)*n+1;i--){
		if(h%2==0){
			if(i==wei){
				l=n-(i-(h-1)*n)+1;
				break;
			}
		}
		else {
			if(i==wei){
				l=i-n*(h-1);
				break;
			}
		}
	}
	cout<<h<<" "<<l;
	return 0;
}
