#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	int n=0,k=0,res=0,lst=0;
	cin>>n>>k;
	vector<int>a(n+1),f(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		f[i]=a[i];
		if(i==1)continue;
		//处理前缀和 
		f[i]^=f[i-1];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=lst;j<i;j++){
			int curk=(f[i]^f[j]);
			if(curk==k){
				lst=i;
				res++;
				break;
			}
		}
		
	}
	
	cout<<res;
	
	return 0;
}
