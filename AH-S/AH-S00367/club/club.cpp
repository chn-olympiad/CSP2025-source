#include<bits/stdc++.h>
using namespace std;
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
long long t,n,sum,a[100005][4];
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]) sum+=a[i][1];
			else if(a[i][1]<a[i][2]&&a[i][2]>a[i][3]) sum+=a[i][2];
			else sum+=a[i][3];
		}
		cout<<sum;
	}
}
