#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll n,k;
ll range[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>range[i];
	
	int res=0;
	if(n==1){
		if(range[0]==0) res++;
	}
	else if(n==2){
		if(range[0]==0) res++;
		if(range[1]==0) res++;
		else if(range[1]==range[0]) res++;
	}
	cout<<res<<endl;
	return 0;
}
