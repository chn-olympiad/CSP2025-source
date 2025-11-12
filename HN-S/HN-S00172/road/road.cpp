#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,K=1e6+5;
struct meaning{
	int a,b;//city number
	int v;//value
}road[N];
long long n,m,k;
bool cmp(meaning x,meaning y){
	if(x.v>=y.v)return false;
	if(x.a>=y.a)return false;
	if(x.b>=y.b)return false;
}

struct meaning1{
	int people;//i
	int c,a[];
	}man[K];
bool cmp1(meaning1 x,meaning1 y){
	if(x.v>=y.v)return false;
	if(x.a>=y.a)return false;
	if(x.b>=y.b)return false;
}
	bool ton[N][N];
int conster(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int a,b,v;
		cin>>a>>b>>v;
		road[i].a=a;
		road[i].b=b;
		road[i].v=v;
	}
	sort(road+1,road+n+1,cmp);
	long long ans=0;//have had "ton[N]"
	for(int i=1,j;i<=n;i++){
		if(ton[road[i].a][road[i].b]&&ton[road[i].b][road[i].a]){
			ans+=road[i].v;
			ton[road[i].a][road[i].b]=false;
			ton[road[i].b][road[i].b]=false;
		}
	}
	
	

	int conster(){
		cin>>n;
		for(int i=1,j=1;j<=n;j++,i+=3){
			int a,b,c;
			cin>>a>>b>>c;
			man[i].aij=a;man[i+1].aij=b;man[i+2].aij=c;
			man[i].people=man[i+1].people=man[i+2].people=j;
			man[i].j=1;man[i+1].j=2;man[i+2].j=3;
		}
		sort(man+1,man+3*n+1,cmp);
		bool ton[N];
		for(int i=1;i<=n;i++)ton[i]=true;
		int a[4];
		a[1]=a[2]=a[3]=0;
		long long ans=0;
		int x=n/2;
		for(int i=1,j;i<=3*n;i++){
			if(ton[man[i].people]&&a[man[i].j]<x){
				ans+=man[i].aij;
				ton[man[i].people]=false;
				a[man[i].j]++;
			}
		}
		return ans;
	}
	return ans;
}
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	
	return 0;
}
