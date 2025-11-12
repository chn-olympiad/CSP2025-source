#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,M,T,A[10001],S[101][101],ans,xx,yy,tot;
bool cmp(int a,int b){return a>b;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>N>>M;
	for(int i=1;i<=N*M;i++) cin>>A[i];
	ans=A[1];
	T=N*M;
	sort(A+1,A+1+T,cmp);
	for(int i=1;i<=T;i++){
		if(A[i]==ans){
			tot=i;
			break;
		}
	}
	for(int i=1;i<=M;i++){
		if(i*N>=tot){
			yy=i;
			break;
		}
	}
	cout<<yy<<" ";
	if(yy%2!=0) cout<<N-yy*N+tot;
	else cout<<yy*N-tot+1;
	return 0;
}