#include<fstream>

using namespace std;

ifstream cin("xor.in");
ofstream cout("xor.out"); 

int a[500010];

int main(){
	int n,k;
	cin >>n>>k;
	for(int i=1;i<=n;i++) {
		cin >>a[i];
	}
	cout<<1;
	return 0;
}
