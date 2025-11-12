#include<bits/stdc++.h>
using namespace std;
int n,m;
int num;
int a[107];
int x=1,y=1;
bool f=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) num=a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			cout<<y<<' '<<x;
			break;
		}
		if(f) x++;
		if(!f) x--;
		if(x>n){
			f=!f;
			y++;
			x--;
		}
		else if(x<1){
			f=!f;
			y++;
			x++;
		}
	}
	return 0;
}
