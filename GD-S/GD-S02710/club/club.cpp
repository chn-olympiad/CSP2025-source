#include<bits/stdc++.h>
using namespace std;
int a[4][11451441],n,q=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			q+=max(a[1][i],max(a[2][i],a[3][i]));
		}
		cout<<q<<endl;
		q=0;
	}
}
