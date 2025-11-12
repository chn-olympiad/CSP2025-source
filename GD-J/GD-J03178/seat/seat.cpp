#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[105],id;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	id=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==id){
			id=i;
			break;
		}
	}
	int x=1,y=1;
	for(int i=2;i<=id;i++){
		if(y%2==1){
			if(x==n) y++;
			else x++;
		}
		else{
			if(x==1) y++;
			else x--;
		}
	}
	cout<<y<<" "<<x;
	return 0;
} 
