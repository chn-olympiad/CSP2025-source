#include<iostream>
#include<algorithm>
#define MAXN 510000
using namespace std;
int n,k,A[MAXN],Pre[MAXN],maxn=-1e9,Ans=0,Len=0;
int Last_r;
struct Node{
	int l,r;
}G[MAXN];
bool cmp(Node x,Node y){
	if(x.r==y.r)return x.l<y.l;
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> A[i];
		Pre[i]=Pre[i-1]^A[i];
	}
	int Sum=0;
	for(int i=1;i<=n;i++)Sum+=Pre[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int Sum=Pre[j]^Pre[i-1];
			if(Sum==k){
				G[++Len].l=i;
				G[Len].r=j;
			}
		}
	}
	sort(G+1,G+Len+1,cmp); 
	Last_r=G[1].r;
	Ans++;
	for(int i=1;i<=Len;){
		while(G[i+1].l<=Last_r&&i+1<=Len)i++;
		if(i+1<=Len)i++;
		else break;
		Ans++;
		Last_r=G[i].r;
		if(i==Len)break;
	}
	cout << Ans << endl;
	return 0;
}
