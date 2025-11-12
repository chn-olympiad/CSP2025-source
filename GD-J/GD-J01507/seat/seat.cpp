//T2
#include <bits/stdc++.h>
using namespace std;
int n,m,r,plr;
int a[1007];
int s[1007];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>a[i];
		s[i] = a[i];
	} 
	r = a[1];
	sort(s+1,s+n*m+1,greater<int>() );
	for(int i = 1;i <= n*m;i++){
		if(r == s[i]){
			plr = i;
			break;
		}
	}
	int x = 1,y = 1;
	plr--;
	while(plr--){
		//cout<<y<<" "<<x<<endl;
		bool f;//0 ио 1 об 
		if(y % 2 == 1) f = 1;
		else f = 0;
		if(f == 1&&x == n) y++;
		else if(f == 0&&x == 1) y++;
		else if(f == 1) x++;
		else if(f == 0) x--;
	}
	cout<<y<<" "<<x; 
	return 0;
}
