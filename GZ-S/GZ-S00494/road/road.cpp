//GZ-S00494  韩智宸 毕节七星关东辰实验学校 
#include<bits/stdc++.h>
using namespace std;
long long n,m,k,q1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
		cin>>m>>k;
	long long a[m][3],c[k][n+1];
	for(int l=0;l<m;l++){
		cin>>a[l][1]>>a[l][2]>>a[l][3];
	}
	for(int l=0;l<k;l++ ){
		for(int o=0;o<=n;o++){
			cin>>c[l][o];
		}
	}
	for(int i=0;i<0;i++){
		q1+=a[l][3];
     }
     cout<<q1;
		return 0;
}


