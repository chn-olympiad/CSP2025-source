#include<bits/stdc++.h>
using namespace std;
int t,n;
int A[100005][3];
struct lazy{
	int a,b;
}B[100005];
int sum;
void dfs(int i=0,int s=0,int a=0,int b=0,int c=0){
	if(a>n/2||b>n/2||c>n/2)return;
	if(i==n){
		sum=max(sum,s);
	}
	dfs(i+1,s+A[i][0],a+1,b,c);
	dfs(i+1,s+A[i][1],a,b+1,c);
	if(A[i][2]!=0)dfs(i+1,s+A[i][2],a,b,c+1);
}
bool cmp(lazy x1,lazy x2){
	return x1.a>x2.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++)
				cin>>A[i][j];
			B[i].a=A[i][0];
			B[i].b=A[i][1];
		}
		sum=0;
		if(A[0][2]==0&&A[0][1]==0){
			sort(B,B+n,cmp);
			for(int i=0;i<n/2;i++){
				sum+=B[i].a;
			}
		}
		else dfs();
		cout<<sum<<endl;
	}
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
