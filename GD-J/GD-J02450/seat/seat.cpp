#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,grade[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>grade[i];
	int r = grade[1];
	sort(grade+1,grade+n*m+1,greater<int>());
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++){
			if(grade[x*m-m+y]==r){
				cout<<x<<" "<<y;
				return 0;
			}
		}
		x++;
		for(int y=m;y>0;y--){
			if(grade[x*m-y+1]==r){
				cout<<x<<" "<<y;
				return 0;
			}
		}
	}
}
