#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int ans;
int flag=0;
int k;
void go(int v,int sum,int g){
	for(int i=v+1;i<=k;i++){
		go(i,sum+a[i],g+1);
	}
	if(g>=2){
		if(sum>a[k]*2){
			ans++;
			ans%=998244353;
		}
	}

}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	sort(a+1,a+n+1);
	//if(flag==0){
		//cout<<(n-1)*(n-2)/2<<" ";
		//return 0;
	//}
	for(int i=n;i>=3;i--){
		k=i;
		go(0,0,0);
	}
	cout<<ans;
	return 0;
}