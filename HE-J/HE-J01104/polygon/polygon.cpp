#include<bits/stdc++.h>
using namespace std;

int n;
int a[5010];

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b>c and a+c>b and c+b>a){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		long long ans = 0;
		for(int i=1;i<=n;i+=1){
			cin>>a[i];
		}
		do{
			for(int i=4;i<=n;i+=1){
				int maxsize=-1;
				int sizesum=0;
				for(int j=1;j<=i;j+=1){
					sizesum+=a[i];
					maxsize = max(maxsize,a[i]);
				}
				if(sizesum>maxsize*2){
					ans+=1;
				}
			}
		}while(next_permutation(a+1,a+1+n));
		cout<<ans%998244353;
	}
	
	return 0;
	
}
