#include<bits/stdc++.h>
using namespace std;
int N,K,A[500005];
bool V[500005];
int Ans=0;
int Dfs(int U,int Sum){
	int Cnt=0;
	if(Sum==K){
		for(int i=U+1;i<=N;i++){
			Cnt=max(Dfs(i,A[i]),Cnt);
		}
		return Cnt+1;
	}else{
		if(U<N){
			return Dfs(U+1,Sum^A[U+1]);
		}else{
			return 0;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool All1=1,All10=1;
	int Cnt1=0,Cnt11=0,Cnt0=0;
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		cin >> A[i];
		if(A[i]!=1){
			All1=0;
		}
		if(A[i]!=1 && A[i]!=0){
			All10=0;
		}
		if(A[i]==1){
			Cnt1++;
		}
		if(A[i]==1 && A[i-1]==1 && V[i-1]==0){
			Cnt11++;
			V[i]=V[i-1]=1;
		}
		if(A[i]==0){
			Cnt0++;
		}
	}
	if(K==0 && All1==1){
		cout << N/2;
		return 0;
	}
	if(All10==1){
		if(K==1){
			cout << Cnt1;
		}else if(K==0){
			cout << Cnt11+Cnt0;
		}else{
			cout << 0;
		}
		return 0;
	}
	for(int i=1;i<=N;i++){
		Ans=max(Ans,Dfs(i,A[i]));
	}
	cout << Ans;
	return 0;
} 
