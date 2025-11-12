#include<iostream>
#include<map>
using namespace std;
int a[10000000];
int b[10000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1) b[i]=a[i] xor b[i-1];
		else b[i]=a[i];
	}
	map<int,int> s;
	int minn=1,ans=0;
	int xorr=0;
	for(int i=1;i<=n;i++){
		int xorrr=xorr;
		if((b[i] xor k xor xorr)==0||(s[b[i] xor k xor xorr]>minn)){
			minn=i;
			ans++;
			xorr=b[i];
		}
		s[b[i] xor xorrr]=i;
	}
	cout<<ans;
	return 0;
}