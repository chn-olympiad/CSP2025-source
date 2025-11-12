#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int tag;
	int a[110];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i == 1) tag = a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i] == tag){
			tag = i;
			break;
		}
	}
	int x = 1,y = 1,c = 0;
	for(int i=1;i<=tag;i++){
		if(i == 1) continue;
		if(c%2 == 0){
			if(x == n){
				y++;
				c = 1;
			}
			else x++;
		}
		else if(c%2 == 1){
			if(x == 1){
				y++;
				c = 0;
			}
			else x--;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
