#include <iostream>
using namespace std;
int a[300];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++){
	int l=i;
	int h=l;
	for(int j=i+1;j<=n;j++){
		int r=j;
		if(h|r==k)
		{cnt++;
		i=r;
		break;}
		else
		h|=r;
	}
	}
	cout<<cnt;
	return 0;
}
