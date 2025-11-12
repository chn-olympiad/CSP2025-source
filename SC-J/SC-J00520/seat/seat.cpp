#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int t=a[1],ans=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				ans++;
				if(a[ans]==t){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				ans++;
				if(a[ans]==t){
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