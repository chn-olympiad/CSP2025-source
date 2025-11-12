#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=35;
const int F=(1>>21);
int n,k; 
int w;
int num;
int a[N];
bool ff;
int maxn;
int cnt;
bool b[N];
int c[F];
bool sum[N][M];
int u[N];
int v[N];
int p;
int l[N];
int wei(int x){
	int sum=0;
	while(x){
		x>>=1;
		sum++;
	}
	return sum;
}
void c1(int x){
	int t=0;
	while(x){
		if(x&1)u[++t]=1;
		else u[++t]=0;
		x>>=1;
	}
}
void init(){
	w=wei(k);
	c1(k);
	for(int i=1;i<=n;i++){
		int s=0;
		int x=a[i];
		while(x){
			if(x&1){
//				cout<<i<<" "<<sum[i][s+1]<<" ";
				++s;
				if(sum[i-1][s]==0)sum[i][s]=1;
				else sum[i][s]=0;
//				cout<<sum[i][s]<<"\n";
			}
			else{
				sum[i][++s]=sum[i-1][s];
			}
			x>>=1;
		}
		for(int j=s+1;j<=21;j++){
			sum[i][j]=sum[i-1][j];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=4;j++){
//			cout<<sum[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
}
int h(int x,int p){
	int gg=0;
	int t=0;
	for(int i=1;i<=21;i++){
		if(sum[x][i]==0&&sum[p][i]==1){
			l[++t]=1;
		}
		else if(sum[x][i]==1&&sum[p][i]==0){
			l[++t]=1;
		}
		else{
			l[++t]=0;
		}
	}
	for(int i=t;i>=1;i--){
		gg=gg*2+l[i];
	}
	return gg;
}
bool check(int x,int p){
	for(int i=1;i<=21;i++){
		if(sum[x][i]==1&&sum[p][i]==0){
			v[i]=1;
		}
		else if(sum[x][i]==1&&sum[p][i]==1){
			v[i]=0;
		}
		else if(sum[x][i]==0&&sum[p][i]==1){
			v[i]=1;
		}
		else{
			v[i]=0;
		}
	}
//	if(x==1){
//		for(int i=1;i<=4;i++){
//			cout<<u[i]<<" ";
//		}
//		cout<<"\n";
//	}
	int t=0;
	int gg=0;
	for(int i=1;i<=21;i++){
		if(v[i]==0&&u[i]==1){
			l[++t]=1;
		}
		else if(v[i]==1&&u[i]==0){
			l[++t]=1;
		}
		else{
			l[++t]=0;
		}
	}
	for(int i=t;i>=1;i--){
		gg=gg*2+l[i];
	}
	if(c[gg]>p||gg==0)return 1;
	else return 0;
}
void f(){
	for(int i=1;i<=n;i++){
		if(check(i,p)){
			p=i;
			cnt++;
//			cout<<i<<"\n";
		}
		else{
			int g=h(i,p);
			c[g]=i;
		}
	}
	cout<<cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ff=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1)ff=0;
		maxn=max(maxn,a[i]);
	}
	if(maxn<k){
		printf("0");
		return 0;
	}
//	if(ff){
//		if(k==0){
//			for(int i=1;i<=n;i++){
//				if(a[i]==0)cnt++;
//				else if(a[i]==1&&a[i-1]==1&&!b[i-1]){
//					b[i]=1;
//					b[i-1]=1;
//					cnt++;
//				}
//			}
//			cout<<cnt<<"\n";
//		}
//		else if(k==1){
//			for(int i=1;i<=n;i++){
//				if(a[i]==1)cnt++;
//			}
//			cout<<cnt<<"\n";
//		}
//		return 0;
//	}
	init();
	f();
	return 0;
} 
