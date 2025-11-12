#include<bits/stdc++.h>
#define IO(x) freopen(#x ".in","r",stdin); freopen(#x ".out","w",stdout);
#define MAXN 110000
#define MAXM 21000
using namespace std;
int t,n,A1,A2,A3,Sum,A[MAXN][4],B[MAXN],C[MAXN],G[MAXN],Ans=-1e9;
struct Node{
	int l,r;	
}S[MAXN];
bool cmp(int a,int b){
	return a>b;
}
bool cmp1(Node a,Node b){
	return a.l>b.l;
}
bool cmp2(Node a,Node b){
	return a.r>b.r;
}
void dfs(int x){
	if(x==n+1){
		int A1=0,A2=0,A3=0;
		for(int i=1;i<=n;i++){
			if(G[i]==1)A1++;
			else if(G[i]==2)A2++;
			else if(G[i]==3)A3++;
		}
		if(A1>n/2||A2>n/2||A3>n/2)return;
		int Sum=0;
		for(int i=1;i<=n;i++)Sum+=A[i][G[i]];
		Ans=max(Ans,Sum);
		return;
	}
	for(int i=1;i<=3;i++){
		G[x]=i;
		dfs(x+1);
	}
}
void Solve(){
	cin >> n;
	int Kind1=0,Kind2=0;
	for(int i=1;i<=n;i++){
		cin >> A[i][1] >> A[i][2] >> A[i][3];
		B[i]=max(A[i][1],max(A[i][2],A[i][3]));
		if(A[i][1]!=0||A[i][3]!=0)Kind1=1;
		if(A[i][3]!=0)Kind2=1;
	}
	if(!Kind1){
		sort(B+1,B+n+1,cmp);
		int Sum=0;
		for(int i=1;i<=n/2;i++)Sum+=B[i];
		cout << Sum << endl;
		return;
	}
	else if(!Kind2){
		int Sum1=0,Sum2=0;
		for(int i=1;i<=n;i++){
			S[i].l=A[i][1];
			S[i].r=A[i][2];
		}
		sort(S+1,S+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(i<=n/2)Sum1+=S[i].l;
			else Sum1+=S[i].r;
		}
		sort(S+1,S+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(i<=n/2)Sum2+=S[i].r;
			else Sum2+=S[i].l;
		}
		cout << max(Sum1,Sum2);
		return;
	}
	dfs(1);
	cout << Ans << endl;
	Ans=-1e9;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)Solve();
	return 0;
}