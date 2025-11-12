#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],b,ans,d;
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
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				ans++;
				if(a[ans]==b){
					cout<<i<<' '<<j;
					d=1;
					break;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				ans++;
				if(a[ans]==b){
					cout<<i<<' '<<j;
					d=1;
					break;
				}
			}
		}
		if(d==1){
			break;
		}
	}
	return 0;
}
