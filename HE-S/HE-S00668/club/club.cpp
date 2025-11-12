#include <bits/stdc++.h>
using namespace std;
long long t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int c=0;
	for(int i=0;i<t;i++){
		long long n=0,bh=0,sum=0;
		cin>>n;
		long long b[3]={};
		long long d[3]={};
		long long e[3][100000]={};
		struct bm2{
			long long bh;
			long long xh;
		}a[100000][3];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				a[i][j].bh=j;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j].xh;
			}
		}
		int x=n/2;
		for(int i=0;i<n;i++){
			if(d[bh]>x){
				d[bh]--;
				if(e[bh][i-1]<b[bh]){
					for(int j=0;j<n;j++){
						e[bh][j]=e[bh][j+1];
					}
				}else{
					b[bh]-=c;
					e[bh][i-1]-=c;
				}
			}
			c=max(a[i][0].xh,max(a[i][1].xh,a[i][2].xh));
			for(int j=0;j<3;j++){
				if(a[i][j].xh==c){
					bh=a[i][j].bh;
					break;
				}
			}
			d[bh]++;
			e[bh][i]=c;
			b[bh]+=c;
		}
		for(int i=0;i<3;i++){
			sum+=b[i];
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
