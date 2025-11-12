#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct st{
	int a,b,c;
}a[N],e;
struct edge{
	int v,w,a1,b1,c1;
}p;
int t,n,cnt,b[N];
void calc(int u,int v,int a1,int b1,int c1){
	if(u==n+1){
		cnt=max(cnt,v);
		return ;
	}
	return ;
}
bool cmp1(st x,st y){
	return x.a>y.a;
}
bool cmp2(st x,st y){
	int c1=x.a-x.b,c2=y.a-y.b;
	return c1<c2;
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cnt=0;
		scanf("%d",&n);
		int f1=1,f2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].c!=0) f2=f1=0;
			if(a[i].b!=0) f1=0;
		}
		if(f1){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				cnt+=a[i].a;
			}
			cout<<cnt<<endl;
		}
		else if(f2){
			queue<int> A,B;
			int len1=A.size(),len2=B.size();
			if(len1>len2){
				for(int i=0;i<n/2;i++){
					cnt+=a[A[i]].a;
				}
				for(int i=n/2;i<len1;i++){
					cnt+=a[A[i]].b;
				}
				for(int i=0;i<len2;i++){
					cnt+=a[B[i]].b;
				}
			}
			else if(len1<len2){
				for(int i=0;i<n/2;i++){
					cnt+=a[B[i]].b;
				}
				for(int i=n/2;i<len1;i++){
					cnt+=a[B[i]].a;
				}
				for(int i=0;i<len2;i++){
					cnt+=a[A[i]].a;
				}
			}
			cout<<cnt<<endl;
		}
		else{
			calc(1,0,0,0,0);
			cout<<cnt<<endl;
		}
	}
	return 0;
}
/*



*/
