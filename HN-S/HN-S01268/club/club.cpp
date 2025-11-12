#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
struct node{
	int s,v,k;
}a[300100];
int w[4];
bool vis[300100];
bool cmp(node x,node y){
	return x.k>y.k;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
//		if(n==2){
//			
//		}
		w[0]=n/2;
		w[1]=n/2;
		w[2]=n/2;
		for(int i=1;i<=3*n;i++){scanf("%d",&a[i].k);a[i].s=i/3+1;a[i].v=i%3;}
		sort(a+1,a+3*n+1,cmp);
		int sum=0;
		for(int i=1;i<=3*n;i++){
			if(w[a[i].v]>=1&&!vis[a[i].s]){
				sum+=a[i].k;
				vis[a[i].s]=true;
				w[a[i].v]--;
			}
		}
		printf("%d",sum);
	}
	return 0;
	//Ren5Jie4Di4Ling5%
}
