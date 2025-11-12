#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long z,t,n,c=0,score=0;
	cin>>t;//◊È
	z=0;
	long long a[100000][3]={0},b[t][3]={0};
	while(z!=t){
		cin>>n;//»À
		cout<<n<<endl;
		for(long long i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		for(long long i=0;i<n;i++){
			a[i][3]=a[i][0];
			for(int j=0;j<2;j++){	
				if(a[i][j]<a[i][j+1]){
					a[i][3]=a[i][j+1];
					c=z+1;
					b[t][c]++;
				}
			}
				score+=a[i][3];
			}
			if(b[t][0]<(n/2)&&b[t][1]<(n/2)&&b[t][2]<(n/2)){
				cout<<score;
			}
		z++;			
		}
	
	return 0;
	}
