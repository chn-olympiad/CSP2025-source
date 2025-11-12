#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,a[5010],cnt,ans;
int main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			for(int k=i+1;k<=j;k++) cnt+=a[k];
			if(cnt<=a[i]) continue;
			ans++;
			for(int k=i+1;k<j;k++) if(cnt-a[k]>a[i]){
				ans++;
			}
			cnt=0;
		}
	}
	cout<<ans;
	return 0;
}

