#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][6],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		long long ans=0;
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]>max(a[i][2],a[i][3])){//1
				x++;
				b[i]=1;
			}else if(a[i][2]>max(a[i][1],a[i][3])){//2
				y++;
				b[i]=2;
			}else{//3
				z++;
				b[i]=3;
			}
		}
		int cnt=0,tot=0;
		if(x>n/2){
			tot=x-n/2;
			for(int i=1;i<=n;i++){
				if(b[i]==1)c[++cnt]=a[i][1]-max(a[i][2],a[i][3]);
			}
		}else if(y>n/2){
			tot=y-n/2;
			for(int i=1;i<=n;i++){
				if(b[i]==2)c[++cnt]=a[i][2]-max(a[i][1],a[i][3]);
			}
		}else if(z>n/2){
			tot=z-n/2;
			for(int i=1;i<=n;i++){
				if(b[i]==3)c[++cnt]=a[i][3]-max(a[i][2],a[i][1]);
			}
		}
		sort(c+1,c+cnt+1);
		for(int i=1;i<=tot;i++)ans-=c[i];
		printf("%lld\n",ans);
//		cout<<ans<<endl;
	}
	return 0;
}
/*Ren5Jie4Di4Ling5%
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
18
4
13

5
2
0 0 0
0 0 0
6
1 0 0
1 0 0
1 0 0
1 0 0
1 0 0
1 0 0
6
1 5 0
2 3 0
4 4 0
2 5 0
1 10 0
0 0 0
8
9 7 1
10 82 1
1 1 1
28 10 8
18 2 1
999 1 0
17 0 0
17 17 17
2
20000 0 0
0 0 0
0
3
26
1169
20000
*/
