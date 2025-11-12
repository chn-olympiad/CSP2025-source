#include<iostream> 
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[m],b[m],value[m];
	int v[n][n]={};
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i]>>value[i];
		 v[a[i]-1][b[i]-1]=value[i];
		v[b[i]-1][a[i]-1]=v[a[i]-1][b[i]-1];
	}
	int vi[k][n],mon[k];
	for(int i=0;i<k;i++){
		cin>>mon[i];
		for(int j=0;j<n;j++){
			cin>>vi[i][j];
		}
	}
	bool c[n]={};
	c[0]=true;
	int s=0;
	for(int i=1;i<n;i++){
		int minn=i+1;
		for(int j=0;j<n;j++){
				for(int m=0;m<k;m++){
					if(v[i][j]!=0){
						v[i][j]=min(v[i][j],vi[m][i]+vi[m][j]);
					}
					else v[i][j]=vi[m][i]+vi[m][j];
				}
				if(v[i][j]<v[i][minn]&&c[j]!=true&&v[i][j]!=0) minn=j;
			}
			s+=v[i][minn];
			c[minn]=true;
		}
	cout<<s<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}