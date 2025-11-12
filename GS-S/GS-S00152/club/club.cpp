#include <bits/stdc++.h>

int t,n ,ans,up,A,B,C;
//int uans =-19;
const int MAX_N = 100020;
int a[MAX_N][3];
//bool v[MAX_N][3]={{0}};

using namespace std;


void  dfs(int k,int uans){	
    ans = max(ans,uans);
    if(k==n)return;//数据长度范围
    //if( A>up || B>up || C>up )return;//组人数范围


    if(A+1<=up){    
		A++;
    	dfs(k+1,uans+a[k][1]);
    	A--;
	}
    if(B+1<=up){
    	B++;	
    	dfs(k+1,uans+a[k][2]);   
		B--;	
	}
	if(C+1<=up){
		C++;
    	dfs(k+1,uans+a[k][3]);	
    	C--;
	}
    return;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

	scanf("%d",&t);
	for(int i =0;i<t;i++){//测试组数
		scanf("%d",&n);
		for(int i=0;i<n;i++){//每组数据 输入
			int t,y,u;
			scanf("%d%d%d",&t,&y,&u);
			a[i][1]=t;
			a[i][2]=y;
			a[i][3]=u;
		}
        A =0;
        B =0;
        C =0;
		up=n/2;
        ans =0;
        //printf("%d",n);
		dfs(-1,0);

        //ans+=ans/3;

		printf("%d\n",ans);
/*		for(int i=0;i<n;i++){
                for(int j = 1;j<4;j++)printf("%d  ",a[i][j]);
                printf("\n");
        }
		printf("\n");
		*/
	}
	return 0;
}
