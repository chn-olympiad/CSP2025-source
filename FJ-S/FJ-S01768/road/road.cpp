#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000][2000],k,b[100050],c[100000],nn,mo,xx,yy,zz;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
//	cout<<n<<endl;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++) a[i][i]=0;
	for(int i=1;i<=m;i++){
	
		cin>>xx>>yy>>zz;
		a[xx][yy]=a[yy][xx]=zz;
	}
	if(k==0){
	for(int kk=1;kk<=n;kk++){
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=n;j++)
		 if(a[i][kk]+a[kk][j]<a[i][j]) a[j][i]=a[i][j]=a[i][kk]+a[kk][j];
	} 
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++) {
			cin>>b[j];
			}
			for(int ii=1;ii<=n;ii++){
				for(int jj=i+1;jj<=n;jj++){
				a[ii][jj]=min(a[ii][jj],b[ii]+b[jj]);
				 a[jj][ii]=a[ii][jj];	
				}
				 
		}
	}
	int w=1;
	c[1]=1;
	nn=1;
	while(nn!=n){
		long long wi=0,mi=9999999;
			
		for(int i=w;i<=n;i++){
		if(c[i]==0&&mi>a[w][i]){
			wi=i;
			mi=a[w][i];
		}	
		}
		c[wi]=1;
		mo+=mi;
		//cout<<mi<<endl;
		w=wi;
		nn++;
		
	}
	cout<<mo;
	return 0;
}

