#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std; 
int scr[1005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> scr[i];
	}
	int scr1=scr[1];
	sort(scr+1,scr+1+n*m,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(scr[i]==scr1){
			cout << x << " " << y;
			break;
		}
		else{
			if(x%2==1){
				if(y<n) y++;
				else x++;
			}
			else if(x%2==0){
				if(y>1)y--;
				else x++;
			}
		}
	}
	return 0;
} 
