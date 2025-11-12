#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,q,f=0;
	long long k,c=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int s=a[i];
			for(int w=i+1;w<=j;w++) s=s^a[w];
			if(s==k){
				c++;
				f=1;
				q=j;
				break;
			}
		}
		if(f){
			i=q;
			f=0;
		}
	} 
	cout<<c;
	return 0;
}
