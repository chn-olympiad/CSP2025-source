#include<bits/stdc++.h>
using namespace std;
int a,t=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	while(~scanf("%d",&a)){
		t*=a;
	}
	srand(t);
	cout<<rand();
	return 0;
}
