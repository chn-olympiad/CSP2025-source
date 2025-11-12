#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
const int X=1e5+50;
int n;
int max1[X];
int min1[X];
int a[X][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	
	
	int b[5];
	for(int z=1;z<=T;z++){
		cin>>n;
		
		memset(max1,0,sizeof(max1));
		for(int i=0;i<=n+5;i++){
			min1[i]=4;
		}
		int sum=0;
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			a[i][4]=N;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>a[i][max1[i]]){
					max1[i]=j;
					
				}
				if(a[i][j]<a[i][min1[i]]){
					min1[i]=j;
				}
			}
			sum+=a[i][max1[i]];
		}
		for(int i=1;i<=n;i++){
			b[max1[i]]++;
		}
		int yx[n+5];
		memset(yx,0,sizeof(yx));
		for(int i=1;i<=n;i++){
			yx[i]=a[i][max1[i]]-a[i][6-max1[i]-min1[i]];
		}
		for(int j=1;j<=3;j++){
			while(b[j]>n/2){
				b[j]--;
				int xyx=N;
				int tc;
				for(int i=1;i<=n;i++){
					if(yx[i]<xyx&&max1[i]==j){
						tc=i;
						xyx=yx[i];
					}
				}
				sum-=yx[tc];
				max1[tc]=6-max1[tc]-min1[tc];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}