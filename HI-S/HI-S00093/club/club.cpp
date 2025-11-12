#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t;
struct node{
	int ans_1,ans_2,ans_3,maxx;
}a[maxn];
//bool cmp_1(const node&x,const node&y){
//	return x.ans_1>y.ans_1;
//}
//bool cmp_2(const node&x,const node&y){
//	return x.ans_2>y.ans_2;
//}
//bool cmp_3(const node&x,const node&y){
//	return x.ans_3>y.ans_3;
//}
bool cmp(int x,int y){
	return x>y;
}
bool check(int a,int b,int c,int d){
	int num=0;
	if(a==b)num++;
	if(a==c)num++;
	if(a==d)num++;
	if(b==c)num++;
	if(b==d)num++;
	if(c==d)num++;
	if(num>2)return false;
	return true; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;int ans=0,ans_0=0;
		cin>>n;int A[n];
		memset(A,0,sizeof(A));
		for(int i=1;i<=n;i++){
			cin>>a[i].ans_1>>a[i].ans_2>>a[i].ans_3;
			ans_0+=max(a[i].ans_1,max(a[i].ans_2,a[i].ans_3));
			A[i]=a[i].ans_1;
		}
		if(n==2){
			ans=-1;
			int b[3],c[3];
			b[1]=a[1].ans_1,b[2]=a[1].ans_2,b[3]=a[1].ans_3;
			c[1]=a[2].ans_1,c[2]=a[2].ans_2,c[3]=a[2].ans_3;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						ans=max(ans,(b[i]+c[j]));
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(n==4){
			ans=-1;
			int b[3],c[3],d[3],e[3];
			b[1]=a[1].ans_1,b[2]=a[1].ans_2,b[3]=a[1].ans_3;
			c[1]=a[2].ans_1,c[2]=a[2].ans_2,c[3]=a[2].ans_3;
			d[1]=a[3].ans_1,d[2]=a[3].ans_2,d[3]=a[3].ans_3;
			e[1]=a[4].ans_1,e[2]=a[4].ans_2,e[3]=a[4].ans_3;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int l=1;l<=3;l++){
							if(check(i,j,k,l))ans=max(ans,(b[i]+c[j]+d[k]+e[l]));
						}
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		ans=0;
		bool flag_A=true;
		for(int i=1;i<=n;i++){
			if((a[i].ans_2!=0)||(a[i].ans_3!=0)){
				flag_A=false;
				break;
			}
		}
		if(flag_A){
			 sort(A+1,A+n+1,cmp);
			 for(int i=1;i<=n/2;i++){
			 	ans+=A[i];
			 }
			 cout<<ans<<"\n";
			 continue;
		}
		cout<<ans_0<<"\n";
	}
	return 0;
}
