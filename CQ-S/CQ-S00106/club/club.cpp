#include<bits/stdc++.h>
using namespace std;
unsigned long long t,n,n1[4];
unsigned long long a[1000005][4];
unsigned long long max1=0;
void ss(unsigned long long step,unsigned long long m){
	if(step>n){
		if(max1<m){
			max1=m;
		}
		return;
	}
	for(int i=1;i<=3;i++){
		if(n1[i]<n/2){
			n1[i]++;
			ss(step+1,m+a[step][i]);
			n1[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	for(unsigned long long k=1;k<=t;k++){
		cin>>n;
		for(unsigned long long i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		ss(1,0);
		cout<<max1;
	}
	return 0;
}

