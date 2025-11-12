#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cout<<abs(((n*m-k+rand())/m-rand()*k)%n*m)%rand();
	return 0;
}

