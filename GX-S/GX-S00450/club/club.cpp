#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("ciub.in",'r',stdin);
	freopen("club.out",'w',stdout);
	int n,m,s,r[4];
	cin>>m;
	int maxn[m+1]={0};
	for(int q=1;q<=m;q++){
		cin>>n;
		int a[4][n+1];
		s=0;
		for(int sb=1;sb<=n;sb++){
			cin>>a[1][sb]>>a[2][sb]>>a[3][sb];
		}
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					s=a[i][1]+a[j][2];
					if(s>maxn[q]&&i!=j){
						maxn[q]=s;
					}
				}
			}
		}else if(n==4){
			for(int b1=1;b1<=3;b1++){
				for(int b2=1;b2<=3;b2++){
					for(int b3=1;b3<=3;b3++){
						for(int b4=1;b4<=3;b4++){
							r[1]=0;
							r[2]=0;
							r[3]=0;
							s=a[b1][1]+a[b2][2]+a[b3][3]+a[b4][4];
							r[b1]++;
							r[b2]++;
							r[b3]++;
							r[b4]++;
							if(s>maxn[q]&&r[1]<=2&&r[2]<=2&&r[3]<=2){
								maxn[q]=s;
							}
						}
					}
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n-i;j++){
					if(a[1][j+1]>=a[1][j]){
						int h=a[1][j];
						a[1][j]=a[1][j+1];
						a[1][j+1]=h;
					}
				}
			}
			for(int i=1;i<=n/2;i++){
				maxn[q]+=a[1][i];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<maxn[i]<<endl;
	}
	return 0;
}
