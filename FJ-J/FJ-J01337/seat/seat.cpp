#include<cstdio>
#include<iostream> 
#include<algorithm>
using namespace std;
int n,m,s,r,cnt,x=1;
int a[105],ans[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+s+1,greater<int>());
	while(x<=m){
		if(x&1){
			for(int i=1;i<=n;i++){
				ans[i][x]=a[++cnt];
				if(a[cnt]==r){
					cout<<x<<" "<<i;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				ans[i][x]=a[++cnt];
				if(a[cnt]==r){
					cout<<x<<" "<<i;
					return 0;
				}
			}
			
		}
		x++;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<ans[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}
//4 5
//1 2 3 4 5 6 7 8 19 29 20 18 12 32 65 26 60 99 100 48
