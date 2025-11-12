#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define int long long
int t,n,a[N][4],num[4];
struct node{
	int max1id,max1v,max2id,max2v,cha;
}b[N];
int cmp1(node x,node y){
	return x.cha>y.cha;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			int maxx=-1,num=0;
			for(j=1;j<=3;j++){
				cin>>a[i][j];
				if(maxx<=a[i][j]){
					b[i].max2v=maxx;
					b[i].max2id=num;
					maxx=a[i][j];
					num=j;
					b[i].max1v=maxx;
					b[i].max1id=num;
				}else{
					if(b[i].max2v<=a[i][j]){
						b[i].max2v=a[i][j];
						b[i].max2id=j;
					}
				}
			}
			b[i].cha=b[i].max1v-b[i].max2v;
		}
		sort(b+1,b+n+1,cmp1);
		int ans=0;
		for(i=1;i<=n;i++){
			int d1=b[i].max1id,d2=b[i].max2id,v1=b[i].max1v,v2=b[i].max2v;
			if(num[d1]<n/2){
				ans+=v1;
				num[d1]++;
			}else{
				ans+=v2;
				num[d2]++;
			}
		}
		num[1]=num[2]=num[3]=0;
//		cout<<ans1<<" "<<ans2<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
