#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
set<int>s;
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int sum=0;
	s.insert(0);
	for(int i=1;i<=n;i++){
		sum^=a[i];
		if(s.find(sum^k)!=s.end())ans++,s.clear();
		s.insert(sum);
	}
	cout<<ans;
	return 0;
}
