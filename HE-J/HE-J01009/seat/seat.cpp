#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101],b=1,x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i!=1&&a[i]>a[1])
			b++;
	}
	for(int i=1;i<b;i++){
		if(x%2==1){
			if(y<m) y++;
			else x++;
		}else{
			if(y>1) y--;
			else x++;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
