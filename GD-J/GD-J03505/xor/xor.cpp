#include<bits/stdc++.h>
using namespace std;
const int M=6e6;
struct Node{
	int l,r;
} N[M];
int last_one[M];
int n,k,id,ans=0;
int S[M];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(last_one,-1,sizeof last_one);
	last_one[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int q;
		cin>>q;
		S[i]=q^S[i-1];
		if(last_one[S[i]^k]!=-1){
			N[++id].l=last_one[S[i]^k]+1;
			N[id].r=i;
		}
		last_one[S[i]]=i;
	}
	int nl=-1;
	for(int i=1;i<=id;i++){
		if(N[i].l>nl){
			ans++;
			nl=N[i].r;
		}
	}
	cout<<ans;
	return 0;
} 
