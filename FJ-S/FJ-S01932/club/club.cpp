#include <bits/stdc++.h>
using namespace std;
int a[100005][3];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(n==2) {
			int a1=a[0][0],a2=a[0][1],a3=a[0][2],b1=a[1][0],b2=a[1][1],b3=a[1][2];
			sort(a[0],a[0]+3,cmp);
			sort(a[1],a[1]+3,cmp);
			if((a1==a[0][0] && b1==a[1][0]) || (a2==a[0][0] && b2==a[1][0]) || (a3==a[0][0] && b3==a[1][0])) cout<<max(a[0][0]+a[1][1],a[0][1]+a[1][0]);
			else cout<<a[0][0]+a[1][0];
		}
		else{
			sort(a[0],a[n],cmp);
			int sum=0;
			for(int i=0;i<n;i++) cout<<a[i][0]<<a[i][1]<<a[i][2]<<endl;
			for(int i=0;i<n/2;i++) sum+=a[0][i];
			cout<<sum;
		}
		cout<<endl;
	}
	return 0; 
}
