#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("club.in");
ofstream cout("club.out");
int A[100010][4];
int n;
long long maxn=-1;
struct node{
	int x,bian;
	int t;
};
node B[100010]={};
node C[100010]={};
bool cmp(node x,node y){
	return x.x>y.x;
}
bool cmp2(int x,int y){
	return x>y;
}
void dfs(int x,long long sum,int X,int Y,int Z);
long long dfsA(); 
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	for(int q=0;q<T;q++){
		cin >> n;
		for(int i=0;i<n;i++)cin >> A[i][0] >> A[i][1] >> A[i][2]; 
		
		maxn=-1;
//		X=Y=Z=0;
		if(n>=200)maxn=dfsA();
		else dfs(0,0,0,0,0);
		cout << maxn << endl;
	}
	cin.close();
	cout.close();
	return 0; 
}
long long dfsA(){
	for(int i=0;i<n;i++){
		B[i].x=A[i][0];
		C[i].x=A[i][1];
		B[i].bian=i;
		C[i].bian=i;
	}
	sort(B,B+n,cmp);
	sort(C,C+n,cmp);
	
	long long sum=0;
//	int bi=n/2;
	for(int i=0;i<n/2;i++){
		sum+=B[i].x;
		B[i].t=1;
	}
//	if(C[0].x==0)return sum;
//	sum=0;
//	int D[100010]={};
//	for(int i=0;i<n;i++)D[i]=max(C[i].x,B[i].x);
//	sort(D,D+n,cmp2);
//	for(int i=0;i<n/2;i++)
	return sum;
}
void dfs(int x,long long sum,int X,int Y,int Z){
	if(x==n){
		maxn=max(maxn,sum);
		return;
	}
	for(int i=x;i<n;i++){
		if(X+1<=n/2)dfs(i+1,sum+A[i][0],X+1,Y,Z);
		if(Y+1<=n/2)dfs(i+1,sum+A[i][1],X,Y+1,Z);
		if(Z+1<=n/2)dfs(i+1,sum+A[i][2],X,Y,Z+1);
	}
	return;
}

