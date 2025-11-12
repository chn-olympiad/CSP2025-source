#include<bits/stdc++.h>
using namespace std;
long long t,a[20005],b[200005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=3*n;j++){
			cin>>a[j];
			b[i+j]=a[j];
		}
		sort(b+1,b+3*n+1);
	if(i<t) continue;
	else for(int i=1;i<=3*n;i++){
		cout<<b[i];
	}
	}
	return 0;
}
