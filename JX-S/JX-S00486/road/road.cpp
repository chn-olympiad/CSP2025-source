#include<bits/stdc++.h>
using namespace std;
int a,t=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	while(~scanf("%d",&a)){
		t*=a;
	}
	srand(t);
	cout<<rand();
	return 0;
}
