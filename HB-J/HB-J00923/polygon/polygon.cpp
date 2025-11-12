#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	ll ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int all=pow(2,n);
	for(int i=7;i<all;i++){
		int x=i,j=0;
		bool b[25];
		while(x){
			b[j++]=x%2;
			x/=2;
		}
		int fir,sum=0,shuliang=0;
		bool flag=0;
		for(int k=0;k<j;k++){
			if(!flag&&b[k]==1) fir=a[j-k-1],flag=1,shuliang++;
			else if(flag&&b[k]==1) sum+=a[j-k-1],shuliang++;
		}
		if(shuliang>=3&&sum>fir) ans++;
		if(b[0]==0){
			for(int k=0;k<j/2;k++){
				swap(b[k],b[j-k-1]);
			}
			int fir,sum=0,shuliang=0;
			bool flag=0;
			for(int k=0;k<j;k++){
				if(!flag&&b[k]==1) fir=a[j-k-1],flag=1,shuliang++;
				else if(flag&&b[k]==1) sum+=a[j-k-1],shuliang++;
			}
			if(shuliang>=3&&sum>fir) ans++;
		}
	}
	cout<<ans-2;
	return 0;
}
