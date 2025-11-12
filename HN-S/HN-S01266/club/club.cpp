#include <bits/stdc++.h> 
using namespace std;
long long n,t,suma,sumb,sumc,sum=0;
struct st{
	long long a,b,c,ma,zd,mi,chos,hao;
	long long a_b,b_c,c_a;
}dp[110000],pop1[110000];
bool cmp1(st A,st B){
	return min(A.a_b,-A.c_a)>min(B.a_b,-B.c_a);
}
bool cmp2(st A,st B){
	return min(-A.a_b,-A.b_c)<min(-B.a_b,B.b_c);
}
bool cmp3(st A,st B){
	return min(A.c_a,-A.b_c)>min(-B.b_c,B.c_a);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n;
		suma=0,sumb=0,sumc=0,sum=0;
		for(int i=1;i<=n;i++){
			cin>>dp[i].a>>dp[i].b>>dp[i].c;
			dp[i].hao=i;
			if(dp[i].a>=max(dp[i].b,dp[i].c)){
				suma++;
				dp[i].chos=1;
			}else if(dp[i].b>=max(dp[i].a,dp[i].c)){
				sumb++;
				dp[i].chos=2;
			}else{
				sumc++;
				dp[i].chos=3;
			}
			dp[i].a_b=dp[i].a-dp[i].b;
			dp[i].b_c=dp[i].b-dp[i].c;
			dp[i].c_a=dp[i].c-dp[i].a;
		}
		
		for(int op=1;op<=n;op++){
			if(dp[op].chos==1) sum+=dp[op].a;
			if(dp[op].chos==2) sum+=dp[op].b;
			if(dp[op].chos==3) sum+=dp[op].c;
		}
		
		if(suma>n/2){
			int len=0;
			for(int i=1;i<=n;i++){
				if(dp[i].chos==1){
					pop1[len+1]=dp[i];
					len++;
				}
			}
			sort(pop1+1,pop1+len+1,cmp1);
			for(int i=n/2+1;i<=len;i++){
				sum-=min(pop1[i].a_b,-pop1[i].c_a);
			
			}
		}
		else if(sumb>n/2){
			int len=0;
			for(int i=1;i<=n;i++){
				if(dp[i].chos==2){
					pop1[len+1]=dp[i];
					len++;
				}
			}
			sort(pop1+1,pop1+len+1,cmp2);
			for(int i=n/2+1;i<=len;i++){
				sum-=min(-pop1[i].a_b,pop1[i].b_c);
				
			}
		}
		else if(sumc>n/2){
			int len=0;
			for(int i=1;i<=n;i++){
				if(dp[i].chos==3){
					pop1[len+1]=dp[i];
					len++;
				}
			}
			sort(pop1+1,pop1+len+1,cmp3);
			for(int i=n/2+1;i<=len;i++){
				sum-=min(-pop1[i].b_c,pop1[i].c_a);
				
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
3
4
4 2 5
4 2 5
5 3 4
5 3 6
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0*/
