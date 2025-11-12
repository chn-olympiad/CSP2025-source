#include<bits/stdc++.h>
using namespace std;
int n,m,x,cnt=1,loc,h,l;
int a[400];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[cnt];
			cnt++;
		}
	}x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]==x){
			loc=i;
		}
	}
	h=(loc+n-1)/n;
	if(loc>n){
		loc%=n;
	}
    if(h%2==0){
    	l=n-loc;
    }else{
    	l=loc;
    }
    cout<<h<<' '<<l;
	return 0;
}
