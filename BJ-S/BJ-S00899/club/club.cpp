#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],max2[100005];
struct node{
	int val,n;
}q[3][100005];
bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int a1=0,a2=0,a3=0,sumn=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int maxn=max(a[i][1],max(a[i][2],a[i][3]));
			if(maxn==a[i][1]){
				max2[i]=max(a[i][2],a[i][3]);
				q[1][++a1].val=a[i][1];
				q[1][a1].n=i;
			}else if(maxn==a[i][2]){
				max2[i]=max(a[i][1],a[i][3]);
				q[2][++a2].val=a[i][2];
				q[2][a2].n=i;
			}else{
				max2[i]=max(a[i][1],a[i][2]);
				q[3][++a3].val=a[i][3];
				q[3][a3].n=i;
			}
			sumn+=maxn;
		}
		int sumx=0;
		if(a1>(n/2)){
			sort(q[1]+1,q[1]+a1+1,cmp);
			for(int i=1;i<=(n/2);i++){
				sumx+=q[1][i].val;
			}
			for(int i=1;i<=a2;i++){
				sumx+=q[2][i].val;
			}
			for(int i=1;i<=a3;i++){
				sumx+=q[3][i].val;
			}
			for(int i=(n/2)+1;i<=a1;i++){
				sumx+=max2[q[1][i].n];
			}
			cout<<sumx;
		}else if(a2>(n/2)){
			sort(q[2]+1,q[2]+a2+1,cmp);
			for(int i=1;i<=(n/2);i++){
				sumx+=q[2][i].val;
			}
			for(int i=1;i<=a1;i++){
				sumx+=q[1][i].val;
			}
			for(int i=1;i<=a3;i++){
				sumx+=q[3][i].val;
			}
			for(int i=(n/2)+1;i<=a2;i++){
				sumx+=max2[q[2][i].n];
			}
			cout<<sumx;
		}else if(a3>(n/2)){
			sort(q[3]+1,q[3]+a3+1,cmp);
			for(int i=1;i<=(n/2);i++){
				sumx+=q[3][i].val;
			}
			for(int i=1;i<=a2;i++){
				sumx+=q[2][i].val;
			}
			for(int i=1;i<=a1;i++){
				sumx+=q[1][i].val;
			}
			for(int i=(n/2)+1;i<=a3;i++){
				sumx+=max2[q[3][i].n];
			}
			cout<<sumx;
		}else{
			cout<<sumn;
		}
	}
	return 0;
}
