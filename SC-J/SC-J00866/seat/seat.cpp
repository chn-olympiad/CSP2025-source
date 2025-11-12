#include<bits/stdc++.h>
using namespace std;
int n,m,a[400],x,cnt=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				if(a[(i-1)*m+cnt]==x){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
			cnt=1;
		}else{
			for(int j=m;j>=1;j--){
				if(a[(i-1)*m+cnt]==x){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
			cnt=1;
		}
	}
	return 0;
}