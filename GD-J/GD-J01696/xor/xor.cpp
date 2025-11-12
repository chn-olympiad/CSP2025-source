#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long a[N],n,k,b[N],xb1[N],xb2[N],jl[N],xb=1;
struct XOR{
	long long xb1,xb2,jl;
//	bool check(XOR o){
//		return jl<o.jl;
//	}
} xor1[N];
bool check(XOR o,XOR oo){
	return oo.jl<o.jl;
}
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i;j++){
			if(b[i]-b[j-1]==k){
				xor1[xb].xb1=j,xor1[xb].xb2=i,xor1[xb++].jl=i-j;
			}
		}
	}
	for(int i=1;i<=xb;i++){
		cout<<xor1[i].xb1<<" "<<xor1[i].xb2<<endl;
	}
	sort(xor1,xor1+xb+1,check);
	for(int i=1;i<=xb;i++){
		cout<<xor1[i].jl<<" ";
	}
	return 0;
} 
