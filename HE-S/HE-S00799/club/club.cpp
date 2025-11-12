#include <bits/stdc++.h>
using namespace std;
int t;
int p[100010][4];
int pt[100010];
int mx;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int num,int sum,int a,int b,int c,int nu){
	if(num==nu){
		mx=max(mx,sum);
		return;
	}
	num++;
	if(a!=0) dfs(num,sum+p[num][1],a-1,b,c,nu);
	if(b!=0) dfs(num,sum+p[num][2],a,b-1,c,nu);
	if(c!=0) dfs(num,sum+p[num][3],a,b,c-1,nu);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		mx=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i][1],&p[i][2],&p[i][3]);
			pt[i]=p[i][1];
		}if(n==100000){
			sort(pt+1,pt+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				mx+=pt[i];
			}
		}else{
			dfs(0,0,n/2,n/2,n/2,n);
		}
		cout<<mx<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
