#include<bits/stdc++.h>
using namespace std;
struct node{
	int score;
	bool p;
};
bool cmp(node x,node y){
	return x.score>y.score;
}
node num[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%d",&num[0].score);
	num[0].p=true;
	for(int i=1;i<n*m;i++){
		scanf("%d",&num[i]);
		num[i].p=false;
	}
	sort(num,num+n*m,cmp);
	int t=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(num[t].p){
				printf("%d %d",i,j);
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
			t++;
		}
		i++;
		for(int j=n;j>=1;j--){
			if(num[t].p){
				printf("%d %d",i,j);
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
			t++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
