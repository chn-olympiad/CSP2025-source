#include<bits/stdc++.h>
using namespace std;
int a[199],n,m,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	for(int i=2;i<=n*m;i++)if(a[i]>a[1])cnt++;
	int l=1,h;
	while(cnt>n*2){
		cnt-=n*2;
		l+=2;
	}
	if(cnt<=n){
		h=cnt;
	}else{
		l++;
		h=n+n-cnt+1;
	}
	cout<<l<<" "<<h<<endl;
	return 0;
} 
