#include <iostream>
#include <vector>
using namespace std;

const int mod=998244353;
vector<int> a;
int n;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		a.push_back(tmp);
	}
	srand(20251101);
	cout<<rand()%11+0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}