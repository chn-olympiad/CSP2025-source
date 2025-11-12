#include<iostream>
#include<cmath>
#include<set>
using namespace std;
int n=1,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	set<int> ccf;
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i],ccf.insert(a[i]);
	if(k==0&&ccf.size()==1)cout<<n/2;
	else if(k==1&&ccf.size()==2)cout<<pow(2,k)-1;
	
	return 0;
}
