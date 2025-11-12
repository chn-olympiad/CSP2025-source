#include<bits/stdc++.h>
using namespace std;

int n,m,k; 
struct road{
	int c1;
	int c2;
	int w;
};
struct county{
	int c;
	int a[1005];
};
county countys[12];
road roads[1000005];

bool ways[1000005];
bool al[1000005];

bool bys(){
	for (int i=0;i<n;i++){
		al[i]=false;
	}
	for (int i=0;i<k;i++){
		if (ways[i]){
			al[roads[i].c1]=true;
			al[roads[i].c2]=true;
		}
	}
	for (int i=0;i<n;i++){
		if (!al[i]){
			return false;
		}
	}
	return true;
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>roads[i].c1>>roads[i].c2>>roads[i].w; 
	}
	for(int i=0;i<k;i++){
		cin>>countys[i].c;
		for(int j=0;j<n;j++){
			cin>>countys[i].a[j];
		}
	}
	
	int res=-1,rem=0;
	
	for (int i=0;i<(1<<m);i++){
		rem=0;
		for (int j=0;j<m;j++){
			if ((i>>j) ^ 1){
				cout<<0;
				ways[j]=0;
			}
			else{
				cout<<1;
				rem+=roads[j].w;
				ways[j]=1;
			}
			
		}
		cout<<endl;
		if (res==-1){
			if(bys()){
				res=rem;
			}
		}
		if (rem<res and bys()){
			res=rem;
		}
	}
	
	cout<<res<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
