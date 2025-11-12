#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],n,k[N],ksize;
long long  s,ge;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>s;
	for(long long i=1;i<=n;++i){
		cin>>a[i];
	}
	for(long long i=1;i<=n;++i){
		if(a[i]==s) ge++,ksize=0;
		else{
			ksize++;
			for(long long o=1;o<=ksize;++o){
				if(o==ksize)k[o]=a[i];
				else k[o]=k[o]^a[i];
				if(k[o]==s){
					ge++,ksize=0;break;
				}
			}
		}
	}
    cout<<ge;
	return 0;
}
