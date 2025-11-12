#include<bits/stdc++.h>
using namespace std;
int a[500];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xiaor,sw;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xiaor=a[1];
	sort(a+1,a+n+1);
	int x=1,y=1;
	bool up_or_down=0;
	for(int i=1;i<=n;i++){
		if(a[i]==xiaor){
			sw=i;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(x%n==0 && x/n%2 && !up_or_down){
			y++;
			up_or_down=1;
		}
		else if(x%n==1 && x/n%2==0 && up_or_down){
			y++;
			up_or_down=0;
		}
		else if(up_or_down) x--;
		else x++;
		if(i==sw) cout<<x<<" "<<y;
	}
	return 0;
}
