#include <iostream>
using namespace std;

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t=0;
	int c;
	cin>>t;
	int a[5][10005];
	int n=0;
	while(t){
		cin>>n;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				c=a[i][1];
				if(c<a[i][j]){
					c=a[i][j];
				}
				c=c+c;
			}
		}
		cout<<c;
	}
	return 0;
}
