//road.cpp
#include<iostream>
#include<vector>

using namespace std;
int r[int(1e4+1)][int(1e4+1)],xc[10][int(1e4+1)],pay[10];bool re[10];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,min=2147483646,money=0,cur;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		if(w<r[u][v] || r[u][v]==0) r[u][v]=w;
		cout<<u<<" to "<<v<<" must $"<<r[u][v]<<endl;
	}
	for(int i=0;i<k;i++){
		cin>>pay[i];
		re[i]=0;
		//cout<<"Vilage "<<i<<" must $"<<pay[i]<<endl;
		for(int j=1;j<n;j++){
			cin>>xc[i][j];
			//cout<<"Vilage "<<i<<" to city "<<j<<" must $"<<xc[i][j]<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<n;j++){
			if(i==j) continue;
			min=r[i][j];
			//cout<<"r["<<i<<','<<j<<"] min "<<min<<endl;
			for(int l=0;l<k;l++){
				cur=xc[l][i]+xc[l][j]+(re[l]?pay[l]:0);
				//cout<<"At Vilage "<<l<<", to city"<<i<<" and "<<j<<" must $"<<cur<<endl;
				if(cur<min){
					min=cur;
					//cout<<"min = cur = "<<min<<endl;
					re[l]=1;
				}
			}
			money+=min;
		//	cout<<"money is $"<<money<<endl; 
		}
	}
	cout<<money;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
