#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,k,a[N],s[N],ans;
map<int,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		s[i]=s[i-1]^a[i];
	}
	int maxx=-1; mp[0]=-1;
	for (int i=1;i<=n;i++){
		int tmp=s[i]^k;
		if(mp[tmp] && maxx<=mp[tmp]){
			maxx=i;
			ans++;
		}	
		mp[s[i]]=i;	
	}
	cout <<ans;
}
