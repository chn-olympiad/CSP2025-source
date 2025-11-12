#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int n,t,a[N][4],f[N],m[4];
struct node {
	int op1,op2;
	int num;
} b1[N],b2[N],b3[N];
struct node1 {
	int op;
	int num;
} b[N];
bool cmp(node1 A,node1 B) {
	return A.num>B.num;
}
bool cmp1(node A,node B) {
	return A.num>B.num;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			f[i]=0;
		}m[1]=0;m[2]=0;m[3]=0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				cin>>a[i][j];
				b[j].num=a[i][j];
				b[j].op=j;
			}
			sort(b+1,b+4,cmp);
			b1[i].num=b[1].num;
			b1[i].op1=i;//xs
			b1[i].op2=b[1].op;//zb
			b2[i].num=b[2].num;
			b2[i].op1=i;
			b2[i].op2=b[2].op;
			b3[i].num=b[3].num;
			b3[i].op1=i;
			b3[i].op2=b[3].op;
		}
		sort(b1+1,b1+n+1,cmp1);
		sort(b2+1,b2+n+1,cmp1);
		sort(b3+1,b3+n+1,cmp1);

		for(int i=1; i<=n; i++) {
			int x=b1[i].op1,y=b1[i].op2;
			if(!f[x]&&m[y]<n/2) {

				ans+=a[x][y];
				f[x]=1;m[y]++;
			}
		}
		for(int i=1; i<=n; i++) {
			int x=b2[i].op1,y=b2[i].op2;
			if(!f[x]&&m[y]<n/2) {

				ans+=a[x][y];
				f[x]=1;m[y]++;
			}
		}
		for(int i=1; i<=n; i++) {
			int x=b3[i].op1,y=b3[i].op2;
			if(!f[x]&&m[y]<n/2) {

				ans+=a[x][y];
				f[x]=1;m[y]++;
			}
		}
		cout<<ans<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
