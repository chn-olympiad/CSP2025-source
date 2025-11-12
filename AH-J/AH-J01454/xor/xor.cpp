#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],s[5000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i]^a[i-1];
	}
	memset(s,-1,sizeof(s));
	s[0]={0};
	int maxn=0;
	for(int i=1;i<=n;i++){
		int tmp=s[a[i]^k];
		if(tmp>=maxn){
			ans++,maxn=i;
		}
		s[a[i]]=i;
	}
	cout<<ans;
	return 0;
}
