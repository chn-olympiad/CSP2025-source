#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > a(1e5+1,vector<int>(4));
vector<int> c(4,0);
vector< vector<int> > v(4); 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int t;
	cin>>t;
	while(t--){
		long long sum=0;
		int n;
		v.clear();
		c[1]=0;
		c[2]=0;
		c[3]=0;
		c[4]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			int maxx=1;
			for(int j=2;j<=3;j++){
				if(a[i][j]>a[i][maxx]){
					maxx=j;
				}
			}
			if(c[maxx]>=n/2){
				for(int j=0;j<v[maxx].size();j++){
					if(v[maxx][j]<a[i][maxx]){
						sum-=v[maxx][j];
						sum+=a[i][maxx];
						v[maxx][j]=a[i][maxx];
						continue;
					}
				}
				if(maxx==1){
					maxx=max(a[i][2],a[i][3]);
					if(c[maxx]>n/2){
						maxx=min(a[i][2],a[i][3]);
					} 
				}else if(maxx==2){
					maxx=max(a[i][1],a[i][3]);
					if(c[maxx]>n/2){
						maxx=min(a[i][1],a[i][3]);
					} 
				}else{
					maxx=max(a[i][2],a[i][1]);
					if(c[maxx]>=n/2){
						maxx=min(a[i][2],a[i][1]);
					} 
				}
			}
			
			c[maxx]++;
			sum+=a[i][maxx];
			v[maxx].push_back(a[i][maxx]);
		}
		cout<<sum<<endl;
	}
	
	
	return 0;
} 
