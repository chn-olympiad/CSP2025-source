#include<bits/stdc++.h>
using namespace std;
int a[5005],q[5005];
bool cmp(int u,int v){
	return u>v;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((j-i>=3)&&(q[j]-q[i-1]>a[j]*2)){
				cnt++;
				cnt%=998244353;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
}
