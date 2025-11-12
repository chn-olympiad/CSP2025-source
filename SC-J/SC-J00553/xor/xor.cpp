#include<bits/stdc++.h>
using namespace std;
//score:75
#define N 20005
int n,k,ans;
int a[N];
int s[N];
vector<int> f;
int dp_item(int x,int y){
	return ((n+(n-x+2))*(x-1)/2)+(y-x);
}
void init(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
}
void collect(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	f.resize(dp_item(n,n)+5,0);
}
void work(){
	//dp but big data is not supported
	for(int l=0;l<=n-1;l++){
		for(int i=1,j=i+l;j<=n;i++,j++){
			//2.使用[i,j]
			//1.使用[i,s][s+1,j]
			//fprintf(stderr,"CALC : %d\n",s[j]^s[i-1]);
			if((s[j]^s[i-1])==k){
				f[dp_item(i,j)]=1;
				//fprintf(stderr,"f[%d][%d] +1 = %d\n",i,j,f[i][j]);
			}
			for(int s=i;s+1<=j;s++){
				f[dp_item(i,j)]=max(f[dp_item(i,j)],f[dp_item(i,s)]+f[dp_item(s+1,j)]);
				//fprintf(stderr,"f[%d][%d] [%d,%d]+[%d,%d] = %d\n",i,j,i,s,s+1,j,f[i][j]);
			}
			
			//system("pause");
		}
	}
	cout<<f[dp_item(1,n)];
}
void solve(){
	collect();
	work();
}
int main(){
	//init();
	solve();
	return 0;
}