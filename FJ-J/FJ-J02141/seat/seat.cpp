#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int rs=a[1],rpos=114514;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
		if(a[i]==rs){
			rpos=n*m-i;//from 0
			break;
		}
		
	int col=(rpos/n)+1;
	int row=rpos%n+1;
	if(col%2==0) row=n-row+1;
	cout<<col<<' '<<row;
	return 0;
}
