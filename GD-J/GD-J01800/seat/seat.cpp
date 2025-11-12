#include<bits/stdc++.h>
using namespace std;
const int N=9100;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			b=a[i];
		}
	}
	sort(a+1,a+1+n*m,greater<int>());
	int x=1,y=1,t=1;
	int sh=1;
	while(a[t]!=b){
		if(y==n&&sh==1){
			sh=0;
			x++;
		}
		else if(y==1&&sh==0){
			sh=1;
			x++;
		}
		else{
			if(sh==1){
				y++;
			}
			else{
				y--;
			}
		}
		t++;
	}
	cout<<x<<' '<<y<<endl;
	return 0;
}
