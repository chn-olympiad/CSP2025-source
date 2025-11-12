#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],x=1,y,R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m/2;i++){
		int k=a[i];
		a[i]=a[n*m-i+1];
		a[n*m-i+1]=k;
	}
	for(int i=1;i<=n*m;i++){
		if(i%n==1){
			y++;
		}else{
			if(y%2==1){
				x++;
			}else{
				x--;
			}
		}
		if(a[i]==R){
			cout<<y<<' '<<x<< endl;
			return 0;
		}
	}
	return 0;
}
