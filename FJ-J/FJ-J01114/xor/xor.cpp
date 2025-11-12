#include <iostream>
#include <vector>
using namespace std;
void lesson()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int left=1,right=1;
	int counts=0;
	while(right<=n){
		int sum=0;
		for(int i=left;i<=right;i++){
			sum^=a[i];
		}
		right++;
		if(sum==k){
			counts++;
			left=right;
		}
	}
	cout<<counts;
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	lesson();
	return 0;
}
