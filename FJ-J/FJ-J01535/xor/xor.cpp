#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],b[500001][20],c[20],dd=-1e9,r;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int h=19;
	int y=k;
	while(h!=-1){
		c[h]=y%2;
		y/=2;
		h--;
	}
	//for(int j=0;j<20;j++)cout<<c[j];
	//cout<<endl;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int j=19;
		y=a[i];
		while(j!=-1){
			b[i][j]=b[i-1][j]+y%2;
			y/=2;
			j--;
		}
		//for(int j=0;j<20;j++)cout<<b[i][j];
		//cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0&&j!=dd-1;j--){
			int d[20],l=0;
			for(int w=0;w<20;w++){
				d[w]=b[i][w]-b[j][w];
				d[w]%=2;
				//cout<<d[w];
			}
			//cout<<" "<<i<<" "<<j<<" "<<dd<<endl;
			for(int e=0;e<20;e++){
				if(d[e]!=c[e]){
					l=1;
					break;
				}
			}
			if(l==0){
				dd=i;
				r++;
				break;
			}
		}
	}
	cout<<r;
	return 0;
}
