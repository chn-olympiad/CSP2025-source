#include<bits/stdc++.h>
using namespace std;
int n,a[100010][3];
int maxC;
int sum=INT_MIN;
void solve(int currentN,int co,int ct,int cth,int currentSum){
	if(currentN==n){
		sum=max(sum,currentSum);
		return;
	}
	for(int i=0;i<3;i++){
		int add=0,o=0,t=0,th=0;
		if(i==0&&co+1<=maxC){
			o++;
			add=a[currentN][i];
		}
		if(i==1&&ct+1<=maxC){
			t++;
			add=a[currentN][i];
		}
		if(i==2&&cth+1<=maxC){
			th++;
			add=a[currentN][i];
		}
		solve(currentN+1,co+o,ct+t,cth+th,currentSum+add);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			for(int z=0;z<3;z++){
				cin>>a[j][z];
			}
		}
		sum=0;
		maxC=n/2;
		solve(0,0,0,0,0);
		cout<<sum<<endl;
	}
}
