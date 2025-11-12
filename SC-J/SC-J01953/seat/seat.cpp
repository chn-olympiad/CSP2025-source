#include <bits/stdc++.h>
using namespace std;
long long n,m,sum,a[105],rcj,idx;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin >>a[i];
	}
	rcj=a[1];
	sort(a+1,a+1+sum,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i]==rcj){
			idx=i;
		}
	}
	int l=(idx+n-1)/n,h=0;
	if(l%2==0){
		h=n-(idx+n-1)%n;
	}
	else h=(idx+n-1)%n+1;
	cout <<l<<" "<<h;
	return 0;
} 