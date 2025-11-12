#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n,d[3][20001],v[3][20001],min[20000],max,p[3],pm,vis=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int z;
	cin>>t;
	for (int i=0;i<t;i++){
		z=0;
		cin>>n;
		for (int j=0;j<n;j++){
			cin>>d[0][j]>>d[1][j]>>d[2][j];
			v[0][j]=d[1][j]-d[0][j];
			v[1][j]=d[1][j]-d[2][j];
			v[2][j]=d[2][j]-d[0][j];
			if (v[0][j]<0) v[0][j]=-v[0][j];
			if (v[1][j]<0) v[1][j]=-v[1][j];
			if (v[2][j]<0) v[2][j]=-v[2][j];
			max=d[0][j];
			pm=1;
			if (max<d[1][j]){
				max=d[1][j];
				pm=2;
				}
			if (max<d[2][j]){
				max=d[2][j];
				pm=3;
			}
		if (pm==1) p[0]++;
		if (pm==2) p[1]++;
		if (pm==3) p[2]++;
		pm=n/2;
		z+=max;
			for (int j=0;j<n;j++){
				min[0]=100000;
				if (p[0]>pm){//p[1],p[2]Ð¡ÓÚn/2 
					if(min[vis]>v[1][j]){
						vis++;
						min[vis]=v[1][j];
					} 
					if(min[vis]>v[2][j]){
						vis++;
						min[vis]=v[2][j];
					} 
				}
			}
		}
	cout<<z<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
