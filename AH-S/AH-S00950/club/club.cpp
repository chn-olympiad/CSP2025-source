#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
struct node1{
	int a,b,c;
};
node1 e[N];
struct node2{
	int a1,b1,c1;
};
node2 e1[N];
struct node3{
	int a2,b2,c2;
};
node3 e2[N];
bool cmp1(node1 x,node1 y){
	return x.a>y.a;
}
bool cmp2(node2 x,node2 y){
	return x.b1>y.b1;
}
bool cmp3(node3 x,node3 y){
	return x.c2>y.c2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,sum1=0,sum2=0,sum3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
			e1[i].a1=e[i].a,e1[i].b1=e[i].b,e1[i].c1=e[i].c;
			e2[i].a2=e[i].a,e2[i].b2=e[i].b,e2[i].c2=e[i].c;
		}
		sort(e+1,e+n+1,cmp1); 
		sort(e1+1,e1+n+1,cmp2); 
		sort(e2+1,e2+n+1,cmp3); 
		for(int i=1;i<=n/2;i++){
			sum1+=e[i].a;
		}
		for(int i=n/2+1;i<=n;i++){
			sum1+=max(e[i].b,e[i].c);
		}
		for(int i=1;i<=n/2;i++){
			sum2+=e1[i].b1;
		}
		for(int i=n/2+1;i<=n;i++){
			sum2+=max(e1[i].a1,e1[i].c1);
		}
		for(int i=1;i<=n/2;i++){
			sum3+=e2[i].c2;
		}
		for(int i=n/2+1;i<=n;i++){
			sum3+=max(e2[i].a2,e2[i].b2);
		}
		cout<<max(sum1,max(sum2,sum3))<<'\n';
	}
	return 0;
}
