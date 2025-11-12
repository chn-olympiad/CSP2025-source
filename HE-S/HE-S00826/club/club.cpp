#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n][3];
		for(int i=0;i<n;i++){
			for (int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		int fenpei[n];
		int fen[n];
		int renshu[3]={0,0,0};
		int bianhao;
		for(int i=0;i<n;i++){
	 	int zuida=-1;
			for(int j=0;j<3;j++){
				if(zuida<a[i][j]){
					if(renshu[j]<n/2){
						fenpei[i]=a[i][j];
						fen[i]=j;
						zuida=a[i][j];
						bianhao=j;
					}else if(i>0){
						for(int k=0;k<i;k++){
							if(fen[k]==j){
								if(a[i][j]-max(a[i][(j+1)%3],a[i][(j+2)%3])>a[k][j]-max(a[k][(j+1)%3],a[k][(j+2)%3])){
									if(a[k][(j+1)%3]<a[k][(j+2)%3]){
										fenpei[k]=a[k][(j+2)%3];
										fenpei[i]=a[i][j];
										bianhao=j;
										renshu[j]--;
										fen[k]=j;
										fen[i]=j;
										zuida=a[i][j];
									}else{
										fenpei[k]=a[k][(j+1)%3];
										fenpei[i]=a[i][j];
										bianhao=j;
										renshu[j]--;
										fen[k]=j;
										fen[i]=j;
										zuida=a[i][j];
									}
								}
							}
						}
					}
				}
			}
			renshu[bianhao]++;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			ans=ans+fenpei[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}








