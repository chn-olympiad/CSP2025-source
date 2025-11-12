#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],n,k,summ[N];
map <int,int> mp;
int z,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		summ[i]=(summ[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		if(mp[summ[i]^k]!=0 || (summ[i]^k)==0){
			int l=mp[summ[i]^k]+1;
			if(l>z){
				z=i;
				cnt++;
			}
		}
		mp[summ[i]]=i;
	}
	cout<<cnt;
	return 0;
}
