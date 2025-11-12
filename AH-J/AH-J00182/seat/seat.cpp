#include<bits/stdc++.h>
using namespace std;
int a[1005];
int n,m,x,ans,cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				cnt++;
				if(a[cnt]==x){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(a[cnt]==x){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
	}
}
