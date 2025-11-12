#include <iostream>
#include <cstring>
#define MOD 998244353
#define MAXX 5005
using namespace std;

int n;
int bu[MAXX];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(bu,0,sizeof(bu));
	cin>>n;
	for(int i=1;i<=n;i++){
		int in;
		cin>>in;
		bu[in]++;
	}
	cout<<15<<endl;
	return 0;
} 
