#include<bits/stdc++.h>
using namespace std;
int a[5024];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,ans,maxn,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		maxn=-10;
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				ans=a[i]+a[j]+a[k];
				maxn=max(max(a[i],a[j]),a[k]);
				if(ans>maxn*2){
					sum++;
				}
			}
		}
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
      
    return 0;
}

