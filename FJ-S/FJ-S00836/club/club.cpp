#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int T,n;
long long x,y,z;
long long q1[MAXN];
long long q2[MAXN];
long long q3[MAXN];
long long sum=0;
int tail1,tail2,tail3;
bool cmp(int a,int b){return a>b;}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		tail1=tail2=tail3=0;
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&x,&y,&z);
			if(x>=y&&x>=z){
				sum+=x;
				q1[++tail1]=min(x-y,x-z);
			}else if(y>=x&&y>=z){
				sum+=y;
				q2[++tail2]=min(y-x,y-z);
			}else{
				sum+=z;
				q3[++tail3]=min(z-y,z-x);
			}
		}
		if(tail1>n/2){
			sort(q1+1,q1+1+tail1,cmp);
			for(int i=tail1;i>n/2;i--)sum-=q1[i];
		}else if(tail2>n/2){
			sort(q2+1,q2+1+tail2,cmp);
			for(int i=tail2;i>n/2;i--)sum-=q2[i];
		}else if(tail3>n/2){
			sort(q3+1,q3+1+tail3,cmp);
			for(int i=tail3;i>n/2;i--)sum-=q3[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}

