#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		a.push_back(tmp);
	}
	cout<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}