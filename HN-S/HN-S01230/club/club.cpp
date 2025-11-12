#include<bits/stdc++.h>
using namespace std;
const int kMaxN=1e5+5;
int t,n,cnt[4];
long long a[kMaxN][4],ans,d[kMaxN];
struct node{
	long long x;
	int id;
}z[kMaxN][4];
bool cmp(node i,node j){
	return i.x>j.x;
}
void S(int sx){
	int b=cnt[sx]-n/2,top=0;
	for(int i=1;i<=n;i++){
		if(z[i][1].id==sx){
			d[++top]=max(z[i][2].x,z[i][3].x)-z[i][1].x;
		}
	}
	sort(d+1,d+top+1);
	for(int i=top;i>=top-b+1;i--) ans+=d[i];
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    for(cin>>t;t;t--){
    	cin>>n;
    	ans=cnt[1]=cnt[2]=cnt[3]=0;
    	for(int i=1;i<=n;i++){
    		int x,w;
    		for(int j=1;j<=3;j++){
    			cin>>z[i][j].x;
    			z[i][j].id=j;
			}
			sort(z[i]+1,z[i]+4,cmp);
		}
		for(int i=1;i<=n;i++){
			cnt[z[i][1].id]++,ans+=z[i][1].x;
		}
		if(cnt[1]>n/2){
			S(1);
		}else if(cnt[2]>n/2){
			S(2);
		}else if(cnt[3]>n/2){
			S(3);
		}
		cout<<ans<<'\n';
	}
    return 0;
}
//Ren5Jie4Di4Ling5%
