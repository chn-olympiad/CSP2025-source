#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+1+n*m,cmp);
	int cnt=0;
	int ans1,ans2;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[++cnt];
				if(a[cnt]==num){
					ans1=i;
					ans2=j;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[++cnt];
				if(a[cnt]==num){
					ans1=i;
					ans2=j;
				}
			}
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
