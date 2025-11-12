#include <bits/stdc++.h>
using namespace std;
int n,m,r;
int s[100005];
bool check(int x,int y){
	if(x>y){
		return true;
	}
	else{
		return false;
	}
}
bool v=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=0;i<n*m;i++){
			cin >>s[i];
	}
	r=s[0];
	sort(s,s+n*m,check);
	int cur=0;
	int x=1,y=1;
	while(cur<n*m){
		if(s[cur]==r) {
			cout <<y<<" "<<x;
			break;
		}
		if(v==1){
			x--;
		}
		else if(v==0){
			x++;
		}
		if(x<1&&y+1<=m){
			x++;
			y++;
			v=0;
		}
		else if(x>n&&y+1<=m){
			x--;
			y++;
			v=1;
		}
		if(x<1&&y+1>m){
			x++;
		}
		else if(x>n&&y+1>m){
			x--;
		}
		cur++;
	}
}
