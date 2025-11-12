#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int T;
int n,m;
struct node{
	int x,e,c;
}f[300005];

bool cmp(node a,node b){
	return a.x>b.x;
}
int ccc[4];
bool flag[100005];
int sum;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ccc[1]=ccc[2]=ccc[3]=0;
		sum=0;
		cin>>n;
		int cnt=0;
		for(int i = 1;i<=n;i++){
			cin>>f[++cnt].x;f[cnt].c=1;f[cnt].e=i;
			cin>>f[++cnt].x;f[cnt].c=2;f[cnt].e=i;
			cin>>f[++cnt].x;f[cnt].c=3;f[cnt].e=i;
			               //duiyingdezu //ren
			flag[i]=0;
		}
		sort(f+1,f+cnt+1,cmp);
		for(int i = 1;i<=cnt;i++){
			//cout<<f[i].x<<endl;
			if(flag[f[i].e]==0&&(ccc[f[i].c]<n/2)){
				//cout<<f[i].x<<' '<<f[i].e<<endl;
				flag[f[i].e]=1;
				ccc[f[i].c]++;
				sum+=f[i].x;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
