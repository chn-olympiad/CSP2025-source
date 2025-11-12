#include<bits/stdc++.h>
using namespace std;
struct Now{
	long long At_best;
	long long Others_best;
	int Id;
};
int N;
long long A[100005][5];
bool cmp(Now x,Now y){
	if(x.At_best==y.At_best){
		return x.Others_best<y.Others_best;
	}else{
		return x.At_best>y.At_best;
	}
}
long long Go_1(){
	bool D_in[100005];
	Now D[100005];
    for(int i=1;i<=N;i++){
    	D_in[i]=0;
    	D[i].At_best=A[i][0];
    	D[i].Others_best=max(A[i][1],A[i][2]);
    	D[i].Id=i;
	}
	sort(D+1,D+N+1,cmp);
	int M=N/2;
	long long Sum1=0;
	for(int i=1;i<=M;i++){
		Sum1+=D[i].At_best;
		D_in[D[i].Id]=1;
	}
	long long Sum2=0;
	for(int i=1;i<=N;i++){
		if(D_in[i]==0){
			Sum2+=max(A[i][1],A[i][2]);
		}
	}
	return Sum1+Sum2;
}
long long Go_2(){
	bool D_in[100005];
	Now D[100005];
    for(int i=1;i<=N;i++){
    	D_in[i]=0;
    	D[i].At_best=A[i][1];
    	D[i].Others_best=max(A[i][0],A[i][2]);
    	D[i].Id=i;
	}
	sort(D+1,D+N+1,cmp);
	int M=N/2;
	long long Sum1=0;
	for(int i=1;i<=M;i++){
		Sum1+=D[i].At_best;
		D_in[D[i].Id]=1;
	}
	long long Sum2=0;
	for(int i=1;i<=N;i++){
		if(D_in[i]==0){
			Sum2+=max(A[i][0],A[i][2]);
		}
	}
	return Sum1+Sum2;
}
long long Go_3(){
	bool D_in[100005];
	Now D[100005];
    for(int i=1;i<=N;i++){
    	D_in[i]=0;
    	D[i].At_best=A[i][2];
    	D[i].Others_best=max(A[i][1],A[i][0]);
    	D[i].Id=i;
	}
	sort(D+1,D+N+1,cmp);
	int M=N/2;
	long long Sum1=0;
	for(int i=1;i<=M;i++){
		Sum1+=D[i].At_best;
		D_in[D[i].Id]=1;
	}
	long long Sum2=0;
	for(int i=1;i<=N;i++){
		if(D_in[i]==0){
			Sum2+=max(A[i][1],A[i][0]);
		}
	}
	return Sum1+Sum2;
}
long long Dp[205][105][105][105];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
    	cin >> N;
    	for(int i=1;i<=N;i++){
	    	cin >> A[i][0] >> A[i][1] >> A[i][2];
		}
		if(N<=200){
			memset(Dp,0,sizeof(Dp));
			long long Ans=0;
			for(int i=1;i<=N;i++){
				for(int l1=0;l1<=N/2;l1++){
					for(int l2=0;l2<=N/2;l2++){
						int l3=i-l1-l2;
						if(l3<0 || l3>N/2){
							continue;
						}
						if(l1>0){
							Dp[i][l1][l2][l3]=max(Dp[i][l1][l2][l3],Dp[i-1][l1-1][l2][l3]+A[i][0]);
						}
						if(l2>0){
							Dp[i][l1][l2][l3]=max(Dp[i][l1][l2][l3],Dp[i-1][l1][l2-1][l3]+A[i][1]);
						}
						if(l3>0){
							Dp[i][l1][l2][l3]=max(Dp[i][l1][l2][l3],Dp[i-1][l1][l2][l3-1]+A[i][2]);
						}
						if(i==N){
							Ans=max(Ans,Dp[i][l1][l2][l3]);
						}
					}
				}
			}
			cout << Ans << endl;
		}else{
			long long Ans=Go_1();
    		Ans=max(Ans,max(Go_2(),Go_3()));
    		cout << Ans << endl;
		}
	}
	return 0;
}