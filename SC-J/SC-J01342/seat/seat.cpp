#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[110],b[20][20],x,xa;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	xa=a[1];
	sort(1+a,1+a+(n*m),cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				x++;
				if(a[x]==xa){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				x++;
				if(a[x]==xa){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}