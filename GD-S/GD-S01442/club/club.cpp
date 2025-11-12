#include<bits/stdc++.h>
using namespace std;
int t,ans=-1;
int n,a[100009][9],b[100009];
struct data{
	int sum[9],big;
}c[100009];
void dfs(int x,int A,int B,int C){
	if(x>n){
		int sum=0;
		for(int i=1;i<=n;i++)sum+=a[i][b[i]+1];
		ans=max(ans,sum);
		return;
	}
	if(A+1<=n/2){
		b[x]=0;
		dfs(x+1,A+1,B,C);
	}
	if(B+1<=n/2){
		b[x]=1;
		dfs(x+1,A,B+1,C);
	}
	if(C+1<=n/2){
		b[x]=2;
		dfs(x+1,A,B,C+1);
	}
}
bool cmmp(data a,data b){
	return a.sum[1]>b.sum[1];
}
void Ax(){
	sort(c+1,c+1+n,cmmp);
	for(int i=1;i<=n/2;i++)ans=ans+c[i].sum[1];
}
bool cmp(data a,data b){
	int maA=max(a.sum[1],max(a.sum[2],a.sum[3]));
	int maB=max(b.sum[1],max(b.sum[2],b.sum[3]));
	return maA>maB;
}
void run(){
	sort(c+1,c+1+n,cmp);
	int s[9];
	s[1]=s[2]=s[3]=0;
	for(int i=1;i<=n;i++){
		if(s[c[i].big]<n/2){
			s[c[i].big]++;
			ans+=c[i].sum[c[i].big];
		}
		else{
			int Max=0,id=0;
			if(c[i].big==1){
				if(c[i].sum[2]>c[i].sum[3])Max=c[i].sum[2],id=2;
				else Max=c[i].sum[3],id=3;
			}
			if(c[i].big==2){
				if(c[i].sum[1]>c[i].sum[3])Max=c[i].sum[1],id=1;
				else Max=c[i].sum[3],id=3;
			}
			if(c[i].big==3){
				if(c[i].sum[2]>c[i].sum[1])Max=c[i].sum[2],id=2;
				else Max=c[1].sum[1],id=1;
			}
			if(s[id]<n/2){
				s[id]++;
				ans+=Max;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int sp_bj=0;
		for(int i=1;i<=n;i++){
			int ma=-1;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				c[i].sum[j]=a[i][j];
				ma=max(ma,a[i][j]);
			}
			if(a[i][2]>0||a[i][3]>0)sp_bj=1;
			if(ma==c[i].sum[1])c[i].big=1;
			else if(ma==c[i].sum[2])c[i].big=2;
			else c[i].big=3;
		}
		ans=0;
		if(n<=10)dfs(1,0,0,0);		
		else if(sp_bj==0)Ax();
		else run();
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
