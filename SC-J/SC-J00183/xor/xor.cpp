#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
using ll=long long;
const int Cnt=5e5+4;
int n,k,A[Cnt],d[Cnt],a=1;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	REP(z,1,n)cin>>A[z];
	REP(z,1,n){
		d[z]=d[z-1];
		if(A[z]==k){
			d[z]=max(d[z],d[z-1]+1);
			a=z;
			continue;
		}
		for(int i=z-1;i>=a;i--){
			A[i]^=A[z];
			if(A[i]==k){
				d[z]=max(d[z],d[i-1]+1);
				a=i;
				break;
			}
		}
	}
	cout<<d[n];
	return 0;
}