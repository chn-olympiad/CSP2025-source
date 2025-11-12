#include<bits/stdc++.h>
using namespace std;

int t,n;
int o[5][100001][3];
int f1,f2,f3;
int js(int a,int b,int c){
	int opt=0;
	for(int i=1;i<=n;i++){
//		printf("%d %d\n",opt,i);
		if(i%3==1)
			opt+=o[a][(i-1)/3+1][1];
		if(i%3==2)
			opt+=o[b][(i-1)/3+1][1];
		if(i%3==0)
			opt+=o[c][(i-1)/3+1][1];
	}
		
			
	return opt;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&o[1][i][1],&o[2][i][1],&o[3][i][1]);
			o[1][i][2]=i;
			o[2][i][2]=i;
			o[3][i][2]=i;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
			
				if(o[1][i][1]<o[1][j][1])
					swap(o[1][i][1],o[1][j][1]),swap(o[1][i][2],o[1][j][2]);
			
				if(o[2][i][1]<o[2][j][1])
					swap(o[2][i][1],o[2][j][1]),swap(o[2][i][2],o[2][j][2]);
			
				if(o[3][i][1]<o[3][j][1])
					swap(o[3][i][1],o[3][j][1]),swap(o[3][i][2],o[3][j][2]);
			}
		int p1=0,p2=0,p3=0;
		for(int i=1;i<=n/3+1;i++)
			p1+=o[1][i][1];
		for(int i=1;i<=n/3+1;i++)
			p2+=o[2][i][1];
		for(int i=1;i<=n/3+1;i++)
			p3+=o[3][i][1];
//		printf("f1 %d f2 %d f3 %d\n",p1,p2,p3);
		if(p1==max(p1,max(p2,p3)))
			if(p2==max(p1,min(p2,p3)))
				f1=1,f2=2,f3=3;
			else
				f1=1,f2=3,f3=2;
		if(p2==max(p1,max(p2,p3)))
			if(p1==max(p1,min(p2,p3)))
				f1=2,f2=1,f3=3;
			else
				f1=2,f2=3,f3=1;
		if(p3==max(p1,max(p2,p3)))
			if(p2==max(p1,min(p2,p3)))
				f1=3,f2=2,f3=1;
			else
				f1=3,f2=1,f3=2;

		printf("%d\n",js(f1,f2,f3));
	}

	return 0;
}
