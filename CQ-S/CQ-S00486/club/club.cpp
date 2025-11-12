#include<bits/stdc++.h>
using namespace std;
int t,n,a[100100][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int b[100100];
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1];
		}
		sort(b+1,b+n+1);
		int top=0;
		for(int i=n/2+1;i<=n;i++) top+=b[i];
		cout<<top<<endl;
	}
	return 0;
}
