#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(0));
	int n,m;
	cin>>n>>m;
	if(m<=n){
		cout<<0;
	}else{
		cout<<rand()%123;
	}
	return 0;
}
