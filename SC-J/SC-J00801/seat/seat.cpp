#include<bits/stdc++.h>
using namespace std;
int n,m;
int Ace,Touch;
int sum;
int x,y;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	Ace=a[1];
	sort(a+1,a+1+n*m,cmp);
	sum=0;
	x=1,y=1;
	for(int ldd=1;ldd<=m;ldd++){
		for(int i=1;i<=n;i++){
			sum++;
			if(i==1){
				if(a[sum]==Ace){
					cout<<y<<" "<<x;
					return 0;
				}
				continue;
			}
			if(ldd%2==0){
				x--;	
			}else{
				x++;
			}if(a[sum]==Ace){
//				cout<<'!'<<sum<<" "<<Ace<<endl;
				cout<<y<<" "<<x;
				return 0;
			}
//			cout<<y<<" "<<x<<endl;
		}
		y++;
	}
	cout<<y<<" "<<x;
	return 0;
}