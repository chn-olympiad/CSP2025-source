#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5; 
int n,k,a[N],b[N],f,ans,s;
map<int,int>p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k; 
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=b[i-1]^a[i];
	p[0]=1;
	for(int i=1;i<=n;i++){	
		if(p[k^b[i]]>f&&p[k^b[i]])ans++,f=i;
		p[b[i]]=i+1;
	}
	cout<<ans;	
	return 0;
}
