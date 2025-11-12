#include <bits/stdc++.h >
using namespace std;
int a[5010];
int b[5010];
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;;i++){
		b[1]+=1;
		int s=0;
		int maxn=0,sum=0;
		for(int j=1;j<=n;j++){
			if(b[j]==2){
				b[j+1]+=1;
				b[j]=0;
			}
			if(b[j]==1){
				s+=1;
				sum+=a[j];
				maxn=a[j];
			}
		}
		if(s>=3 && sum>2*maxn){
			ans+=1;
			
		}		
		if(s==n){
			cout<<ans;
			return 0;
		}

	}
}