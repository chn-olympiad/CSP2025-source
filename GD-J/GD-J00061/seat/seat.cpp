#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int h=a[0];
	sort(a+0,a+(n*m),cmp);
	int x=1,y=1;
	for(int i=0;i<n*m;i++){
		x++;
		if(x==n+1){
			x=1;
			y++;
		}
		if(a[i]==h){
			cout<<x<<" "<<y;
			break;
		}
	}
} 
