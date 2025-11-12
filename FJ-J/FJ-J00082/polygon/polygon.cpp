#include<bits/stdc++.h>
using namespace std;

int a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n<=20){
		for(int i=3;i<=n;i++){
			for(int j=1;j<=n;j++){
				int sum=0;
				int maxx=-1;
				int x=0;
				if(i+j-1>n){
					break;
				}else{
					x=i+j-1;
				}
				for(int w=j;w<=x;w++){
					sum+=a[w];
					if(maxx<a[w]){
						maxx=a[w];
					}
				}
				if(sum>2*maxx){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
