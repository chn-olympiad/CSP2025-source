#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x[n][m];
	int num=0,a[n*m],b[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int zz=a[0];
	for(int i=0;i<n*m;i++){
		int maxn=-1,tmp;
		for(int j=0;j<=n*m;j++){
			if(a[j]>maxn){
				maxn=a[j];
				tmp=j;
			}
		}
		b[i]=maxn;
		a[tmp]=-1;
	}
	int num_tmp=0;
	if(n%2==0){
		for(int j=1;j<=n/2;j++){
			for(int i=0;i<m;i++){
				x[num][i]=b[num_tmp];
				num_tmp++;
			}
			num++;
			for(int i=m-1;i>0;i++){
				x[num][i]=b[num_tmp];
				num_tmp++;
			} 
			num++;
		}
	}
	else{
		for(int j=1;j<=n/2;j++){
			for(int i=0;i<m;i++){
				x[num][i]=b[num_tmp];
				num_tmp++;
			}
			num++;
			for(int i=m-1;i>0;i++){
				x[num][i]=b[num_tmp];
				num_tmp++;
			} 
			num++;
		}
		for(int i=0;i<m;i++){
				x[num][i]=b[num_tmp];
				num_tmp++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(x[i][j]==zz){
				cout<<i<<" "<<j;
			}
		}
	}
	
	return 0; 
 } 
