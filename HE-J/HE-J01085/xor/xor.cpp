#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N];
bool xzA(){
	for(int i=1;i<=n;i++)if(a[i]!=1)return 0;
	return 1;
}
bool xzB(){
	for(int i=1;i<=n;i++)if(a[i]!=1&&a[i]!=0)return 0;
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(xzA()&&k==0){
		printf("%d",n/2);
		return 0;
	}else if(xzB()){
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}else if(i+1<=n&&a[i+1]==1){
					ans++,i++;
				}
			}printf("%d",ans);
			return 0;
		}else if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1)ans++;
			printf("%d",ans);
			return 0;
		}
	}else if(k==0){
		int t[5010]={0},ans=0;
		for(int i=1;i<=n;i++)t[a[i]]++;
		for(int i=1;i<=5000;i++)ans+=t[i]/2;
		printf("%d",ans+t[0]);
	}else{
		int sum=0;
		for(int i=1;i<=n;i++)sum+=a[i];
		printf("%d",sum/k);
	} 
	return 0;
} 
