#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	long long n,m;
	int a[100000][10];
	cin>>t>>n;
	while(t--){
		m=0;
		cin>>n;
		for(int i=0;i<=n+1;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]<=a[i][2]){
				m+=a[i][2];
			}else if(a[i][1]<=a[i][3]){
				m+=a[i][3];
			}else{
				m+=a[i][1];
			}
		}
		cout<<m<<endl;
	}
	return 0;
}
