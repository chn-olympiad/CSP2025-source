#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long t,n,a[N+5][10],b[N+5][10],sum=0;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			b[j][1]=a[j][1];b[j][2]=a[j][2];b[j][3]=a[j][3];
			sort(b[j]+1,b[j]+4,cmp);
		}
		for(int i=1;i<=n;i++){
			sum+=b[i][1];
		}
	}
	cout<<sum;
	return 0;
} 
