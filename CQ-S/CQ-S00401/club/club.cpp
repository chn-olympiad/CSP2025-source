#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,t,a[N][3],one[N],two[N],thr[N],x,y,z;
struct node{
	int id,gf,gs,gt;
};
node aa[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin >> t;
    while (t--){
    	cin >> n;
    	int sum=0;
    	for (int i=1;i<=n;i++){
    		cin >> a[i][1] >> a[i][2] >> a[i][3];
    		int f=max(a[i][1],max(a[i][2],a[i][3]));
    		int t=min(a[i][1],min(a[i][2],a[i][3]));
    		int s=min(a[i][1],max(a[i][2],a[i][3]));
    		for (int j=1;j<=3;j++){
    			if (a[i][j]==f) aa[i].gf=j;
    			else if (a[i][j]==t) aa[i].gt=j;
    			else if (a[i][j]==s) aa[i].gs=j;
			}
		}
		for (int i=1;i<=n;i++){
			if (aa[i].gf==1) one[++x]=i;
			else if (aa[i].gf==2) two[++y]=i;
			else if (aa[i].gf==3) thr[++z]=i;
		}
		for (int i=1;i<=n/2;i++){
			sum+=a[two[i]][2]+a[thr[i]][3]+a[one[i]][1];
		}
		cout << sum << "\n";
	}
	return 0;
}

