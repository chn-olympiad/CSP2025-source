#include<bits/stdc++.h>
using namespace std;
//财大气粗ccf也是用上Ultra9了 
int a[100001][3];
struct node{
	int maxw,minw,midw,now;
}b[100001];
bool cmp(node x,node y){
	if(a[x.now][x.midw]==0&&a[x.now][x.minw]==0&&a[y.now][y.midw]==0&&a[y.now][y.minw]==0) return a[x.now][x.maxw]>a[y.now][y.maxw];
	else if(a[x.now][x.midw]==0&&a[x.now][x.minw]==0) return true;
	else if(a[y.now][y.midw]==0&&a[y.now][y.minw]==0) return false;
	if(a[x.now][x.maxw]!=a[y.now][y.maxw]) return a[x.now][x.maxw]>a[y.now][y.maxw];
	else if(a[x.now][x.midw]!=a[y.now][y.midw]) return a[x.now][x.midw]>a[y.now][y.midw];
	else return a[x.now][x.minw]>a[y.now][y.minw];
}
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int maxx=max(a[i][1],max(a[i][2],a[i][3]));
			int minx=min(a[i][1],min(a[i][2],a[i][3]));
			b[i].now=i;
			if(maxx==a[i][1]) b[i].maxw=1;
			if(maxx==a[i][2]) b[i].maxw=2;
			if(maxx==a[i][3]) b[i].maxw=3;
			if(minx==a[i][1]) b[i].minw=1;
			if(minx==a[i][2]) b[i].minw=2;
			if(minx==a[i][3]) b[i].minw=3;
			b[i].midw=6-b[i].maxw-b[i].minw;
		}
		sort(b+1,b+n+1,cmp);
		int people[4]={},i=1,ans=0;
		bool my[4];
		while(i<=n){
			if(b[i].maxw==0){
				b[i].maxw=b[i].midw;
				b[i].midw=b[i].minw;
				b[i].minw=0;
			}
			if(my[b[i].maxw]){
				b[i].maxw=0;
				continue;
			}
			ans+=a[b[i].now][b[i].maxw];
			people[b[i].maxw]++;
			b[i].maxw=0;
			b[i].midw=0;
			b[i].minw=0;
			i++;
			if(people[1]==n/2) my[1]=1;
			if(people[2]==n/2) my[2]=1;
			if(people[3]==n/2) my[3]=1;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
