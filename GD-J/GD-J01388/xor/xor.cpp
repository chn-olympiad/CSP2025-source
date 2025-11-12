#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10; 
int n,k,a[N],s[N],ans;
bool v[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	while(1){
		int mi=1e9,z,y;
		bool vv=false;
		for(int i=1;i<=n;i++){
			if(v[i])
			    continue;
			for(int j=i;j<=n;j++){
				if(v[j]||j-i+1>mi)
				    break;
				if((s[j]^s[i-1])==k){
	            	mi=j-i+1,z=i,y=j;
	            	vv=true;
				}
			}
		}
		if(!vv)
		    break;
		for(int i=z;i<=y;i++)
		    v[i]=true;
		ans++;
	}
	cout<<ans;
	return 0;
} 
