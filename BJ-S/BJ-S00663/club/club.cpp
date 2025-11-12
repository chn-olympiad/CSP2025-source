#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
long long t,n,d1[N],d2[N],d3[N];
struct node{
	long long x;
	int idx;
};
long long ans=0;
node d4[N];
long long pk;
bool A=1,B=1,C=1;
bool cmp(int x,int y){
	return x>y;
}
bool cmpn(node a,node b){
	return a.x>b.x;
}
void dfs(int i,int a,int b,int c,long long sts){
	if(i>n){
		ans=max(ans,sts);
		return ;
	}
	if(a<pk){
		dfs(i+1,a+1,b,c,sts+d1[i]);
	}
	if(b<pk){
		dfs(i+1,a,b+1,c,sts+d2[i]);
	}
	if(c<pk){
		dfs(i+1,a,b,c+1,sts+d3[i]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
		cin>>n;
		pk=n/2;
		for(int i=1;i<=n;i++){
			cin>>d1[i]>>d2[i]>>d3[i];
			if(d2[i]!=0){
				A=0;
			}
			if(d3[i]!=0){
				B=0;
			}
		}
		if(A){
			sort(d1+1,d1+1+n,cmp);
			for(int i=1;i<=pk;i++){
				ans+=d1[i];
			}
		}
		else if(B){
			for(int i=1;i<=n;i++){
				d4[i].x=d1[i]-d2[i];
				d4[i].idx=i;
			}
			sort(d4+1,d4+1+n,cmpn);
			for(int i=1;i<=pk;i++){
				ans+=d1[d4[i].idx];
			}
			for(int i=pk+1;i<=n;i++){
				ans+=d2[d4[i].idx];
			}
		}
		else{
			dfs(0,0,0,0,0);
		}
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
