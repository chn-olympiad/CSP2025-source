#include<bits/stdc++.h>
using namespace std;
int n,a[100005][5],n2,p[100005][5],ma=-1,cc[100005];
struct p{
	int s1,s2,c;
}d[100005];
void dfs(int c[4],int d,int h,int x){
	if(h==n+1){
		p[h][x]=max(p[h][x],d);
	//	cout<<"[]"<<d<<endl;
		ma=max(ma,d);
		return ;
	}
	for(int i=1;i<=3;i++){
		c[i]++;
		if(c[i]<=n2){
		//	cout<<h<<" "<<i<<endl;
//			if(p[h][i]!=0){
//				s+=p[]
//			}
			dfs(c,d+a[h][i],h+1,i);
			p[h][i]=p[h+1][i];
			
		}
		c[i]--;
	}
}
void dgs(){
//	cout<<"*";
//	int d[100005];
	for(int i=1;i<=n;i++){
		if(a[i][1]>a[i][2]&&cc[a[i][1]]<=n2){
			cc[a[i][1]]++;
			ma+=a[i][1];
		}else if(cc[a[i][2]]<=n2){
			ma+=a[i][2];
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int f=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[1][3]!=0) f=1;
		}
		if(f==0){
			dgs();
		}
		n2=n/2;
		ma=-1;
		int c[4]={0};
		dfs(c,0,1,0);
		cout<<ma<<endl;
	}
	
} 
