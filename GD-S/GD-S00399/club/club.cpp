#include <bits/stdc++.h>
using namespace std;
struct node{
	int a1,a2,a3;
	int sum;
}x2[100005],x1[100005],x[100005],q[100005];
bool cmp(node a,node b){
	return a.sum>b.sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int c1,c2,c3;
		c1=c2=c3=0;
		for (int i=1;i<=n;i++){
			int a,b,c;
			cin >> a >> b >> c;
			if ((a==0 && b==0) || (a==0 && c==0) || (b==0 && c==0)) x2[++c1].a1=a,x2[c1].a2=b,x2[c1].a3=c,x2[c1].sum=a+b+c;
			else if (a==0 || b==0 || c==0) x1[++c2].a1=a,x1[c2].a2=b,x1[c2].a3=c,x1[c2].sum=a+b+c;
			else x[++c3].a1=a,x[c3].a2=b,x[c3].a3=c,x[c3].sum=a+b+c;
		}
		sort(x2+1,x2+c1+1,cmp);
		sort(x1+1,x1+c2+1,cmp);
		sort(x+1,x+c3+1,cmp);
		for (int i=1;i<=c2;i++){
			q[i].a1=x1[i].a1;
			q[i].a2=x1[i].a2;
			q[i].a3=x1[i].a3;
		}
		for (int i=1;i<=c1;i++){
			q[i+c2].a1=x2[i].a1;
			q[i+c2].a2=x2[i].a2;
			q[i+c2].a3=x2[i].a3;
		}
		for (int i=1;i<=c3;i++){
			q[i+c1+c2].a1=x[i].a1;
			q[i+c1+c2].a2=x[i].a2;
			q[i+c1+c2].a3=x[i].a3;
		}
		int n1,n2,n3;
		n1=n2=n3=0;
		int sum=0;
		for (int i=1;i<=n;i++){
			int maxn=max(max(q[i].a1,q[i].a2),q[i].a3);
			if (maxn==q[i].a1){
				if (n1+1<=n/2){
					sum+=q[i].a1;
					n1++;
				}else{
					int d=max(q[i].a2,q[i].a3);
					if (d==q[i].a2){
						if (n2+1<=n/2){
							sum+=q[i].a2;
							n2++;
						}else{
							sum+=q[i].a3;
							n3++;
						}
					}
				}
			}if (maxn==q[i].a2){
				if (n2+1<=n/2){
					sum+=q[i].a2;
					n2++;
				}else{
					int d=max(q[i].a1,q[i].a3);
					if (d==q[i].a1){
						if (n1+1<=n/2){
							sum+=q[i].a1;
							n1++;
						}else{
							sum+=q[i].a3;
							n3++;
						}
					}
				}
			}if (maxn==q[i].a3){
				if (n3+1<=n/2){
					sum+=q[i].a3;
					n3++;
				}else{
					int d=max(q[i].a1,q[i].a2);
					if (d==q[i].a1){
						if (n1+1<=n/2){
							sum+=q[i].a1;
							n1++;
						}else{
							sum+=q[i].a2;
							n2++;
						}
					}
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
