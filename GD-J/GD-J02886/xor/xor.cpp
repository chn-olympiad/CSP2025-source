#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int l[500010][22];
bool vis[500010];
struct cd{
	int c,d;
}ls[125000000010];
int check(int a,int b){
	int sum=0;
	for(int i=0;i<21;i++) sum+=(l[b][i]-l[a][i])%2*pow(2,i);
	return sum;
}

bool cmp(cd a,cd b){
	return a.d-a.c<b.d-b.c;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,index=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int j=0,m;
		cin>>m;
		while(m>0){
			l[i][j++]=m%2;
			m/=2;
		}
	}
	for(int i=2;i<=n;i++)
		for(int j=0;j<21;j++)
			l[i][j]+=l[i-1][j];
	for(int i=0;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(check(i,j)==k){
				ls[index].c=i;
				ls[index++].d=j;
			}
	sort(ls,ls+index,cmp);
	for(int i=0;i<index;i++){
		bool flag=1;
		for(int j=ls[i].c;j<=ls[i].d;j++)
			if(vis[j]){
				flag=0;
				break;
			}
		if(flag){
			ans++;
			for(int j=ls[i].c;j<=ls[i].d;j++) vis[j]=1;
		}
	}
	cout<<ans;
}
