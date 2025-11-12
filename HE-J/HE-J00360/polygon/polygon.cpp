#include<bits/stdc++.h>
using namespace std;
const long long N=10e5+10;
long long n,a[N],ans;
long long maxx(long long a[],long long l,long long r){
	long long res;
	for(int i=l;i<r;i++){
		res=max(res,a[i]);
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	if(n<3){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=3;j<=n+1;j++){
			long long res=0;
			for(int k=i;k<j;k++){
			
				res+=a[k];
			}

			if(res<2*maxx(a,i,j)&&j-i>2){
				ans++;
			
			}
		}
	}
	cout<<ans;
}
