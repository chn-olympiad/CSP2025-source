#include<bits/stdc++.h>
using namespace std;
struct club{
	int n;
	int n2;
	int a[100000][5];
	bool yfb[100000];
	int bao[5];
	int sum;
	int hgd;
	int ygg;
}T[10];
int t,hgd[100000],fct[100000],f_cnt=0,jb[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>T[i].n;
		for(int j=1;j<=T[i].n;j++){
			for(int k=1;k<=3;k++){
				cin>>T[i].a[j][k];
			}
		}
	}
	for(int i=1;i<=t;i++){
		T[i].bao[5]={0};
		T[i].sum=0;
		T[i].yfb[100000]={0};
		T[i].n2=0;
		T[i].ygg=0;
		for(int k=1;k<=3;k++){
			T[i].n2=0;
			T[i].ygg=0;
			for(int j=1;j<=T[i].n;j++){
				if(T[i].yfb[j]==0){
					T[i].hgd=T[i].a[j][k];
					hgd[T[i].n2]=T[i].hgd;
					T[i].n2++;
				}
			}
			sort(hgd+1,hgd+T[i].n2+1);
			for(int l=T[i].n2;l>(T[i].n/2)-1;l--){
				if(hgd[l]!=hgd[T[i].n/2]){
					T[i].bao[k]+=hgd[l];
					for(int j=1;j<=T[i].n;j++){
						if(hgd[l]==T[i].a[j][k]){
							T[i].yfb[j]==1;
							T[i].ygg++;
						}
					}
				}
				else{
					for(int j=1;j<=T[i].n;j++){
						if(hgd[l]==T[i].a[j][k]&&T[i].yfb==0){
							fct[f_cnt]=T[i].a[j][k+1];
							jb[f_cnt]=j;
							f_cnt++;
						}
					}
					sort(fct,fct+f_cnt);
					for(int l=0;l<T[i].n/2-T[i].ygg;l++){
						if(fct[l]!=fct[T[i].n/2]){
							T[i].bao[k]+=hgd[l];
							for(int j=1;j<=T[i].n;j++){
								if(hgd[l]==T[i].a[j][k]){
									T[i].yfb[j]==1;
								}
							}
						}
					}
				}
			}
			T[i].sum+=T[i].bao[k];
		}
		cout<<T[i].sum<<endl;
	}
	return 0;
}
