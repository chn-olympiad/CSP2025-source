#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long T,n,m,ma=0;
long long a[N],b[N],c[N],d[N],e[N],f[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int k=n/2,l=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			ma=max(a[i],b[i]);
			l+=max(ma,c[i]); 
			ma=0;
		}
		cout<<l<<endl;
	}
	return 0;
}
