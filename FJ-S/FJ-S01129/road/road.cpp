#include<bits/stdc++.h>
using namespace std;
struct E{
	int U,V;
	long long W;
}G[1000005];
int N,M,K,Fa[10005];
long long C[15],A[15][10005],Ans;
bool cmp(E x,E y){
	return x.W<y.W;
}
int GF(int x){
	if(Fa[x]==x){
		return x;
	}
	return GF(Fa[x]);
}
void Ku(){
	for(int i=1;i<=N;i++){
		Fa[i]=i;
	}
	sort(G+1,G+M+1,cmp);
	for(int i=1;i<=M;i++){
		int U=G[i].U,V=G[i].V;
		long long W=G[i].W;
		if(GF(U)!=GF(V)){
			Fa[GF(V)]=U;
			Ans+=W;
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> N >> M >> K;
	for(int i=1;i<=M;i++){
		int U,V;
		long long W;
		cin >> U >> V >> W;
		G[i].U=U;
		G[i].V=V;
		G[i].W=W;
	}
	bool D=1;
	for(int i=1;i<=K;i++){
		cin >> C[i];
		if(C[i]!=0){
			D=0;
		}
		for(int j=1;j<=N;j++){
			cin >> A[i][j];
			if(A[i][j]!=0){
				D=0;
			}
		}
	}
	if(D==1 && K!=0){
		cout << 0;
	}else{
		Ku();
		cout << Ans;
	}
}