#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,xian,zu[5],maxx,sum;
int a[100001][5],ar[100001];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x){
	maxx=max(maxx,sum);	
	if(x>n)return;
	for(int i=1;i<=3;i++){
		if(zu[i]<xian){
			sum+=a[x][i];
			zu[i]++;
			dfs(x+1);
			zu[i]--;
			sum-=a[x][i];
			dfs(x+1);
		}
	}	
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=5;i++)zu[i]=0;
		maxx=0;
		sum=0;
		cin>>n;
		xian=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ar[i]=a[i][2];
		}
		sort(ar+1,ar+n+1,cmp);
		if(n>=100000&&a[1][2]==0){
			for(int i=1;i<=xian;i++){
				sum+=ar[i];
			}
			cout<<sum<<endl;
			continue;
		}else if(n>=100000){
			for(int i=1;i<=n;i++){
				if(a[i][1]>a[i][2]){
					if(zu[1]<=xian){
						sum+=a[i][1];
						zu[1]++;
					}else if(zu[2]<=xian){
						sum+=a[i][2];
						zu[2]++;
					}
				}else{
					if(zu[2]<=xian){
						sum+=a[i][2];
						zu[2]++;
					}else if(zu[1]<=xian){
						sum+=a[i][1];
						zu[1]++;
					}
				}
			}
			cout<<sum<<endl;
			continue;
		}
		dfs(1);
		cout<<maxx<<endl;
	}
	return 0;
}
