#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int ab[100001][4];
int bb[5];
int jyh[31][31][31][31];
int seee;
int dfs(int a){
	int a1=bb[1],a2=bb[2],a3=bb[3];
	if(a==seee+1)
	return 0;
	if(jyh[a][a1][a2][a3]!=-1){
		return jyh[a][a1][a2][a3];
	}

	int ans=0;
	for(int i=1;i<=3;i++){
		if(bb[i]<seee/2){
			bb[i]++;
			ans=max(ans,dfs(a+1)+ab[a][i]);
			bb[i]--;
		}
	}
	return jyh[a][a1][a2][a3]=ans; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,a,b,c,d,e,f;
	cin>>t;
	for(int i=1;i<=t;i++){
		scanf("%d",&a);
		bb[1]=0;
		bb[2]=0;
		bb[3]=0;
		for(int j=1;j<=a;j++){
			for(int k=0;k<=a;k++){
				for(int f=0;f<=a;f++){
					for(int g=0;g<=a;g++){
						jyh[j][k][f][g]=-1;
					}
				}
			}
			for(int k=1;k<=3;k++){
				scanf("%d",&ab[j][k]);
			}
		}
		seee=a;
		printf("%d\n",dfs(1));
	}
	return 0;
} 