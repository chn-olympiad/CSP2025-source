#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,q;
int qzxor[N],anscnt;
struct ans{
	int l,r;
}qj[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<n+1;i++){
		cin>>q;
		qzxor[i]=qzxor[i-1]^q;
	}
	for(int i=1;i<n+1;i++){
		for(int j=i;j<n+1;j++){
			bool f=0;
			if((qzxor[j]^qzxor[i-1])==k){
				anscnt++;
				f=1;
			}
			if(f){
				i=j;
				break;
			}
		}
	}
	cout<<anscnt;
	return 0;
}
