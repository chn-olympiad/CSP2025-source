#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100010][4],xuan[100010];
int chu[4],pp[100010];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=3;i++)chu[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j];
			int maxn=-1e9;
			for(int j=1;j<=3;j++){
				if(a[i][j]>maxn){
					maxn=a[i][j],xuan[i]=j;
				}
			}
			chu[xuan[i]]++;
		}
		int maxn=0,pos=0;
		for(int i=1;i<=3;i++){
			if(chu[i]>maxn){
				maxn=chu[i],pos=i;
			}
		}
		if(maxn<=n/2){
			int sum=0;
			for(int i=1;i<=n;i++)sum+=a[i][xuan[i]];
			cout<<sum<<"\n";
			continue;
		}
		int sum=0;
		for(int i=1;i<=n;i++)sum+=a[i][xuan[i]];
		int tot=0;
		for(int i=1;i<=n;i++){
			if(xuan[i]!=pos)continue;
			int maxn=0;
			for(int j=1;j<=3;j++){
				if(j==pos)continue;
				maxn=max(maxn,a[i][j]);
			}
			pp[++tot]=a[i][xuan[i]]-maxn;
		}
		sort(pp+1,pp+tot+1);
		for(int i=1;i<=maxn-n/2;i++)sum-=pp[i];
		cout<<sum<<"\n";
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
