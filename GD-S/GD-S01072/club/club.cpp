#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][3],t,n,sum,w[3],mx[N][2];
vector<int> d[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;sum=0;
		for(int i=0;i<3;i++) w[i]=0,d[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++) cin>>a[i][j];
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
				sum+=a[i][0],w[0]++;
				if(a[i][1]>a[i][2]) d[0].push_back(a[i][0]-a[i][1]);
				else d[0].push_back(a[i][0]-a[i][2]);
			}
			if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]){
				sum+=a[i][1],w[1]++;
				if(a[i][0]>a[i][2]) d[1].push_back(a[i][1]-a[i][0]);
				else d[1].push_back(a[i][1]-a[i][2]);
			} 
			if(a[i][2]>a[i][0]&&a[i][2]>a[i][1]){
				sum+=a[i][2],w[2]++;
				if(a[i][0]>a[i][1]) d[2].push_back(a[i][2]-a[i][0]);
				else d[2].push_back(a[i][2]-a[i][1]);
			}
		}
		for(int i=0;i<3;i++) sort(d[i].begin(),d[i].end());
		for(int i=0;i<3;i++) //cout<<(int)d[i].size()-n/2<<' ';
			for(int j=0;j<(int)d[i].size()-n/2;j++) sum-=d[i][j];
			
		cout<<sum<<endl;
	}
} 
