#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int a[N],mark[N];

int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int maxn=-1,minn=N;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	if(k==0&&maxn==1){
		cout<<n;
		return 0;
	}
	long long ans=0;
	if(maxn==1&&minn==0){
		int x;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				
			}
		}
	}
	else{
		int x=a[1];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				
				for(int y=i;y<=j;y++){
					if((x^y)==k)
				}
			}
		}
	}
	
	return 0;
}
