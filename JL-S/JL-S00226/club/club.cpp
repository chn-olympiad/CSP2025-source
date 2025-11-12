#include<bits/stdc++.h>
using namespace std;
int a[100010][5];
int c[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int cc=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a[i][0]=a[i][1];
			a[i][4]=1;
			if(a[i][2]>a[i][0]){
				a[i][0]=a[i][2];
				a[i][4]=2;
			}
			if(a[i][3]>a[i][0]){
				a[i][0]=a[i][3];
				a[i][4]=3;
			}
			c[a[i][4]]++;
			cc+=a[i][0];
		}
		cout<<cc<<endl;
	}
	return 0;
}
