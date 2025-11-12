#include <iostream>
using namespace std;
int a[3][100004];
int bumen[3];
int n;
int mx(int m){
	int x=0;
	int y=0;
	for(int i=1;i<=n;i++){
		if(a[m][i]>x){
			x=a[m][i];
			y=i;
		}
	}
	a[m][y]=0;
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		for(int i=1;i<=n;i++){
			if(i%3==0){
				cnt+=mx(3);
			}
			else{
				cnt+=mx(i%3);
			}
		}
		cout<<cnt;
	}
	return 0;
}
