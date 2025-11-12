#include<bits/stdc++.h>
using namespace std;

int n,m;
int goal,t,cnt;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	cin>>t;
	for(int i=1;i<n*m;i++){
		cin>>goal;
		if(goal>t) ++cnt;
	}
	++cnt;
	if(cnt%n==0) cout<<cnt/n<<" "<<(cnt/n%2==0 ? 1 : n);
	else cout<<cnt/n+1<<" "<<((cnt/n+1)%2==1 ? cnt%n : n-cnt%n+1);
}
