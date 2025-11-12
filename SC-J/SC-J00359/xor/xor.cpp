#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=5e5+5;
int c[5000005];
int a[N],b[N];
int n,k;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	c[0]=1;
	int f=1,ans=0;
	for(int i=1;i<=n;i++){
		int l=b[i]^k;
		if(c[l]>=f or a[i]==k){
			ans++;
			f=i;
		}
		c[b[i]]=i;
	}cout<<ans;
	return 0;
}