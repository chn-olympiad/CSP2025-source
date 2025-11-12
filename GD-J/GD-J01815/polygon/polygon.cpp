#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=5000+10;
int a[maxn];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a+0,a+n);
	cout<<(a[0]+a[1]>a[2]?1:0)<<endl;
	return 0;
}
