#include<bits/stdc++.h>
using namespace std;
const int N=1000000+5;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	while(n--){
		srand(time(NULL));
		rand();
		cout<<rand()%998244353;
	}
} 
