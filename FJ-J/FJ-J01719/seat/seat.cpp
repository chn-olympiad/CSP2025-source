#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//#Shang4Shan3Ruo6Shui4
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	int ans=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ans++;
				if(R==a[ans]){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				ans++;
				if(R==a[ans]){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
