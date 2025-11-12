#include<bits/stdc++.h>
using namespace std;
int n,m,R,num=1,sum=1,a[101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in1","r",stdin);
	freopen("seat.out1","w",stdout);
	freopen("seat.in2","r",stdin);
	freopen("seat.out2","w",stdout);
	freopen("seat.in3","r",stdin);
	freopen("seat.out3","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int c=1;c<=m;c++){
		if(num==n){
			for(int r=num;r>=1;r--){
			    if(a[sum]==R){
				    cout<<c<<" "<<r;
				    return 0;
			    }
			    num=r;
			    sum++;
		    }
		}else{
			for(int r=num;r<=n;r++){
			    if(a[sum]==R){
				    cout<<c<<" "<<r;
				    return 0;
			    }
			    num=r;
			    sum++;
		    }
		}	
	}
	return 0;
}
