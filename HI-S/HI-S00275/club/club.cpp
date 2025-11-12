#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int maxn[6],maxn1[6],qq[6][3],bb[6][3];
int aaa[6][N];
long long t,n,a,b,c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int ans=n/2;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			
			maxn[i]=max(a,max(b,c));
			maxn1[i]+=maxn[i];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<maxn1[i]<<endl;
	}
	return 0;
}
