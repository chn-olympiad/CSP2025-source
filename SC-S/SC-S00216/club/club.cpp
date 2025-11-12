#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define vamos return 0;
using namespace std;
const int mx=3e5+10;
int t;
struct node{
		int man;
		int bu;
		int ren;
	}m[mx];	
bool cmp(node a,node b){
	return a.man>b.man;
}
long long jisuan(int n){	
	for(int i=0;i<=mx;i++){
		m[i].bu=0;
		m[i].man=0;
		m[i].ren=0;
	}
	int check1[4]={0,0,0,0};
	bool check2[mx];
	for(int i=0;i<=mx;i++) check2[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			int y;
			cin>>y;
			m[i*j].man=y;
			m[i*j].bu=j;
			m[i*j].ren=i;
		}
	}
	sort(m+1,m+(3*n)+1,cmp);
	long long ans=0;
	int i=1;
	while(i<=3*n){
		if(check2[m[i].ren]==0&&check1[m[i].bu]<(n/2)){
			ans+=m[i].man;
			check2[m[i].ren]=1;
			check1[m[i].bu]++;
		}
		i++;
	}
	cout<<ans<<endl;		
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++){
		int n;
		cin>>n; 
		jisuan(n);
	}
	vamos
} 