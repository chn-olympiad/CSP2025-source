#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in ","r",stdin);
	freopen("club.out ","w",stdout);
	int p;
	vector<int> l;
	cin>>p;
	for(int u=1;u<=p;u++){
		int n;
		cin>>n;
		vector<int> a[100001];
		vector<int> b[10];
		int c=0;
	for(int i=1;i<=n;i++){
		int u=0,v=-0,w=0;
		cin>>u>>v>>w;
		a[i].push_back(u);
		a[i].push_back(v);
		a[i].push_back(w);
		int m=-1;
		if(u>=v&&u>=w){
			b[1].push_back(i);
			int s=b[1].size();
			int z=0;
			if(s-c>n/2){
				int min=20001,x=0;
				for(int j=0;j<s;j++){
					int y=b[1][j];
					if(y>=0){
						if(a[y][0]-a[y][1]<=min){
						min=a[y][0]-a[y][1];
						m=y;
						x=j;
						z=1;
					}
					if(a[y][0]-a[y][2]<=min){
						min=a[y][0]-a[y][2];
						m=y;
						x=j;
						z=2;
					}
					}
				}
				c++;
				b[1][x]=-1;
				if(z==1)b[2].push_back(m);
			if(z==2)b[3].push_back(m);
			}
		}
		else if(v>=w){
			b[2].push_back(i);
			int s=b[2].size(),z=0;
			if(s-c>n/2){
				int min=20001,x=0;
				for(int j=0;j<s;j++){
					int y=b[2][j];
					if(y>=0){
						if(a[y][1]-a[y][0]<=min){
						min=a[y][1]-a[y][0];
						m=y;
						x=j;
						z=1;
					}
					if(a[y][1]-a[y][2]<=min){
						min=a[y][1]-a[y][2];
						m=y;
						x=j;
						z=2;
					}
					}
				}
				c++;
				b[2][x]=-1;
				if(z==1)b[1].push_back(m);
			if(z==2)b[3].push_back(m);
			}
		}
        else {
			b[3].push_back(i);
			int s=b[3].size(),z=0;
			if(s-c>n/2){
				int min=20001,x=0;
				for(int j=0;j<s;j++){
					int y=b[3][j];
					if(y>=0){
						if(a[y][2]-a[y][0]<=min){
						min=a[y][2]-a[y][0];
						m=y;
						x=j;
						z=1;
					}
					if(a[y][2]-a[y][1]<=min){
						min=a[y][2]-a[y][1];
						m=y;
						x=j;
						z=2;
					}
					}
				}
				c++;
				b[3][x]=-1;
				if(z==1)b[1].push_back(m);
			if(z==2)b[2].push_back(m);
			}
		}
	}
	for(int i=1;i<=3;i++){
		int s=b[i].size();
		for(int j=1;j<=s;j++){
			int y=b[i][j];
			if(y>0){
				l[u]+=a[y][i-1];
			}
		}
	}
}
for(int i=1;i<=p;i++){
	cout<<l[i]<<endl;
}
	return 0;
}
