#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
long long n,a[10001],l,r,cnt,sum,maxn;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			l=i;
			r=j;
			//cout<<l<<" "<<r<<"\n";
			long long maxn=-0x3f3f3f3f,sum=0;
			if(r-l+1>=3){
				//cout<<l<<" "<<r<<"\n";
				for(int k=l;k<=r;k++){
					sum+=a[k];
					maxn=max(maxn,a[k]);
				}
				if(sum>maxn*2){
					cnt=(cnt+1)%998244353;
					//cout<<cnt<<" ";
				}
			}
	        
		}
	}
	cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
