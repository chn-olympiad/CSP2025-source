#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5,MAXM=2e4+2;
int a[MAXN],b[MAXN],c[MAXN],chose[MAXN];

int club[3]={0,0,0};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	int move[MAXM];
	for(int i=1;i<=t;i++){
		memset(move,0,sizeof(move));
		memset(club,0,sizeof(club));
		int n;
		cin >> n;
		int ma=0;
		for(int j=1;j<=n;j++){
			cin >> a[j] >> b[j] >> c[j];
			if(a[j]>=b[j]&&a[j]>=c[j]){
				club[0]++;
				chose[j]=0;
				ma+=a[j];
			}
			else if(b[j]>=a[j]&&b[j]>=c[j]){
				club[1]++;
				chose[j]=1;
				ma+=b[j];
			}
			else{
				club[2]++;
				chose[j]=2;
				ma+=c[j];
			}
		}
		for(int j=0;j<3;j++){
			if(club[j]>n/2){
				for(int k=1;k<=n;k++){
					if(chose[k]==j){
						if(j==0){
							move[min(a[k]-b[k],a[k]-c[k])]++;
						}
						else if(j==1){
							move[min(b[k]-a[k],b[k]-c[k])]++;
						}
						else move[min(c[k]-a[k],c[k]-b[k])]++;
					}
				}
				int ind=0;
				while(club[j]>(n/2)){
					int mv=min(club[j]-(n/2),move[ind]);
					ma-=ind*mv;
					club[j]-=move[ind];
					ind++;
				}
				break;
			}
		}
		cout << ma << endl;
	}
	return 0;
} 
