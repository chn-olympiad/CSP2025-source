#include<bits/stdc++.h>

using namespace std;
int w[500010];
int n,k;
int cnt=0;
bool vis[500010];
struct node{
	int x,y;
};
node a[500010];
bool cnp(const node& a,const node& b){
	return a.y<b.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	int t=0;
	for(int i=1;i<=n;i++){
		int cw=w[i];
		if(cw==k){
			a[++t].x=i;
			a[t].y=i;
		}
		for(int j=i+1;j<=n;j++){
			cw^=w[j];
			if(cw==k){
				a[++t].x=i;
				a[t].y=j;
			}
		}
	}
	sort(a+1,a+1+t,cnp);
	int cnt=0;
	int rrr=0;
	for(int i=1;i<=t;i++){
		if(a[i].x>rrr){
			rrr=a[i].y;
			cnt++;
		}
	}
	cout<<cnt;

	return 0;
} 
