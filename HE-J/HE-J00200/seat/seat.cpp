#include<bits/stdc++.h>
using namespace std;
int n,m,cha,lie,hang;
int a[105];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c=a[1];
	sort(a+1,a+n*m+1,cmp);
    cha=a[1]-c;
	lie=cha/n+1;
    if(lie%2==0){
    	hang=n-cha%n;
	}else{
        hang=cha%n+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
