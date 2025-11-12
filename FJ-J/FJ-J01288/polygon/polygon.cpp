#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
int N;
long long A[5005],C[5005][5005],Cnt=0;
bool V[5005];
void Dpolygon(int D,long long Sum,long long Max,int Id){
	if(D>=3){
		if(Sum<=Max*2){
			return;
		}
		Cnt=(Cnt+1)%Mod;
	}
	for(int i=Id+1;i<=N;i++){
		if(V[i]==0){
			V[i]=1;
			Dpolygon(D+1,Sum+A[i],max(Max,A[i]),max(Id,i)); 
			V[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> N;
	bool All1=1;
	for(int i=1;i<=N;i++){
		cin >> A[i];
		if(A[i]!=1){
			All1=0;
		}
	}
	if(All1==1){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=i;j++){
				if(j==1 || j==i){
					C[i][j]=1;
				}else{
					C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
				}
			}
		}
		for(int i=3;i<=N;i++){
			Cnt=(Cnt+C[N][i])%Mod;
		}
	}else if(N==3){
		long long D=max(A[1],max(A[2],A[3])),S=A[1]+A[2]+A[3];
		if(S-D>D){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}else{
		Dpolygon(0,0,0,0);
	}
	cout << Cnt%Mod;
	return 0;
} 
