#include<bits/stdc++.h>
using namespace std;
const int N=5005;
long long n,a[N],ge;
void hao(long long q,long long w,long long sum){
	for(long long i=q;i<w;++i){
		if((sum+a[i])>a[w]){
			//cout<<q<<" "<<w<<" "<<sum+a[i]<<" "<<a[w]<<endl;
			++ge;
			ge%=998244353;
		}
		hao(i+1,w,sum+a[i]);
	}return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n); 
	for(long long i=3;i<=n;++i){
		//for(long long o=1;o<=i-2;++o){
			hao(1,i,0);
		//}
	}
	cout<<ge%998244353;
	return 0;
}
