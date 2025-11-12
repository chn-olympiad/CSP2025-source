#include<bits/stdc++.h>
using namespace std;
int v[6];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T>>n;
	int a[T+1][n+1][4],b[n+1][5];
	int s[4];
	for(int t;t<=T;t++){
		for(int i=1;i<=n;i++){
			cin>>a[t][i][1]>>a[t][i][2]>>a[t][i][3];
			b[i][1]=1;
			b[i][2]=2;
			b[i][3]=3;
			b[i][0]=0;
		}
		for(int i=1;i<=n;i++){
			for(int x=1;x<=3;x++){
				for(int y=1;y<=3;y++){
					if(a[t][i][y]<=a[t][i][y+1]){
						swap(a[t][i][y],a[t][i][y+1]);
						swap(b[i][y],b[i][y+1]);
					}
				}
			}
		}
		for(int i=1;i<=3;i++){
			s[i]=0;
			for(int j=1;j<=n;j++){
				if(b[j][1]==i&&b[j][0]==0){
					s[i]++;
					b[j][0]=i;
					//cout<<i;
				}
				if(b[j][1]==0&&b[j][2]==i&&b[j][0]==0){
					s[i]++;
					b[j][0]=i;
					//cout<<i;
				}
				if(b[j][1]==0&&b[j][2]==0&&b[j][3]==i&&b[j][0]==0){
					s[i]++;
					b[j][0]=i;
					//cout<<i;
				}	
			}
			if(s[i]>n/2){
				for(int x=1;x<=n;x++){
					for(int y=1;y<=n;y++){
						if(a[t][x][i]<a[t][y][i]){
							swap(a[t][y][1],a[t][y+1][1]);
							swap(a[t][y][2],a[t][y+1][2]);
							swap(a[t][y][3],a[t][y+1][3]);
							swap(b[y][0],b[y+1][0]);
							swap(b[y][1],b[y+1][1]);
							swap(b[y][2],b[y+1][2]);
							swap(b[y][3],b[y+1][3]);
						}
					}
				}
				int f1=s[i]-n/2,f2=n;
				while(f1>0){
					if(b[f2][0]==i){
						b[f2][i]=0;
						b[f2][1]=0;
				 		f2--;
						f1--;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(b[i][0]==b[i][j]){
					v[t]+=a[t][i][b[i][j]];
				}
			}
		}
	}
	for(int i=1;i<=T;i++){
		cout<<v[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
