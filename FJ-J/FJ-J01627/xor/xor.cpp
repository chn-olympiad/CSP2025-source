#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500005];
int s[500005];
int f[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i]^s[i-1];
		s[i]=x;
	}
	for(int i=1;i<=n;i++){
		int x=s[i-1];
		for(int j=i;j<=n;j++){
			int y=s[j]^x;
			if(y==k){
				f[i]=j;
				break;
			}
		}
//		cout<<i<<" "<<f[i]<<endl; 
	}
	int id=0,minn,sum=0;
	for(int i=1;i<=n;i++){
		if(id==0){
			id=f[i];
			minn=f[i];
		}
		if(id==i){
			sum++;
			i=minn;
			id=0;
		}else{
			if(f[i]!=0) 
				minn=min(minn,f[i]);
		}
//		cout<<i<<" "<<minn<<endl;
	}
	cout<<sum<<endl;
	return 0;
}
//15*5=75
