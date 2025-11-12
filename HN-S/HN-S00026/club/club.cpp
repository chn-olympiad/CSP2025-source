#include<bits/stdc++.h>
using namespace std;
int T,num,daan,sum;
int p[50000][3];
int tp[50005];
int a,b,c;
int jl;
bool camp(int x,int y){
	return x>y;
}
void dfs(int k)
{
	if(k>num) {
		if(sum>=daan) daan=sum;
		return;
	}
	else{
		for(int i=1;i<=3;i++){
			if(i==1&&a<num/2){
				a++;
				sum=sum+p[k][i];
				k=k+1;
				dfs(k);
				k--;
				a--;
				sum=sum-p[k][i];
			}
			else if(i==2&&b<num/2){
				b++;
				sum=sum+p[k][i];
				k=k+1;
				dfs(k);
				b--;
				k--;
				sum=sum-p[k][i];
		}
			else if(i==3&&c<num/2){
				c++;
				sum=sum+p[k][i];
				k=k+1;
				dfs(k);
				c--;
				k--;
				sum=sum-p[k][i];
        }
    }
    }   
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&num);
		if(num<=30){
		for(int j=1;j<=num;j++) {scanf("%d %d %d",&p[j][1],&p[j][2],&p[j][3]);}
		daan=0;
		sum=0;
		a=0,b=0,c=0;
		dfs(1);
		printf("%d",daan);}
		else {
			for(int j=1;j<=sum;j++){
				scanf("%d %d %d",&p[j][1],&p[j][2],&p[j][3]);
				tp[j]=p[j][1];
				if(p[j][2]!=0) jl++;
			}
				sort(tp+1,tp+num+1,camp);
				for(int j=1;j<=num/2;j++) sum+=tp[j];
				for(int j=num/2+1;j<=num;j++) sum+=max(p[j][2],p[j][3]);
				printf("%d",sum);
		}
	}
	return 0;
}
