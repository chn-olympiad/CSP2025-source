#include<bits/stdc++.h>
using namespace std;
int n,m;
pair<int,int> a[105];
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.first>y.first;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int b;
	for(int i=1;i<=n*m;i++)cin>>b,a[i]={b,i};
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[++cnt].second==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[++cnt].second==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
