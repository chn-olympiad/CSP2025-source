#include<bits/stdc++.h>
#define int long long int 
using namespace std;
const int N=1e5+10;
struct Node{
	int a,b,c,vis,id,jian;
}d[N];
int t,n,q[N],qq[N],qqq[N],cnt,cntt,cnttt;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0,shua=0,shub=0,shuc=0;
		cnt=cntt=cnttt=0;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
//			if(d[i].a==d[i].b||d[i].a==d[i].c) cout<<"***\n";
			if(d[i].a>d[i].b&&d[i].a>d[i].c){
				ans+=d[i].a;
				shua++;
				d[i].id=1;
				d[i].jian=d[i].a-max(d[i].b,d[i].c);
				cnt++;
				q[cnt]=d[i].jian;
			}
			else if(d[i].b>d[i].a&&d[i].b>d[i].c){
				ans+=d[i].b;
				shub++;
				d[i].id=2;
				d[i].jian=d[i].b-max(d[i].a,d[i].c);
				cntt++;
				qq[cntt]=d[i].jian;
			}
			else if(d[i].c>d[i].a&&d[i].c>d[i].b){
				ans+=d[i].c;
				shuc++;
				d[i].id=3;
				d[i].jian=d[i].c-max(d[i].b,d[i].a);
				cnttt++;
				qqq[cnttt]=d[i].jian;
			}
			else if(d[i].a==d[i].b){
				ans+=d[i].a;
				if(shua>=shub){
					shub++;
					d[i].id=2;
					d[i].jian=d[i].b-max(d[i].a,d[i].c);
					cntt++;
					qq[cntt]=d[i].jian;
				}
				else{
					shua++;
					d[i].id=1;
					d[i].jian=d[i].a-max(d[i].b,d[i].c);
					cnt++;
					q[cnt]=d[i].jian;
				}
			}
			else if(d[i].a==d[i].c){
				ans+=d[i].a;
				if(shua>=shuc){
					shuc++;
					d[i].id=3;
					d[i].jian=d[i].c-max(d[i].b,d[i].a);
					cnttt++;
					qqq[cnttt]=d[i].jian;
				}
				else{
					shua++;
					d[i].id=1;
					d[i].jian=d[i].a-max(d[i].b,d[i].c);
					cnt++;
					q[cnt]=d[i].jian;
				}
			}
			else if(d[i].b==d[i].c){
				ans+=d[i].b;
				if(shub>=shuc){
					shuc++;
					d[i].id=3;
					d[i].jian=d[i].c-max(d[i].b,d[i].a);
					cnttt++;
					qqq[cnttt]=d[i].jian;
				}
				else{
					shub++;
					d[i].id=2;
					d[i].jian=d[i].b-max(d[i].a,d[i].c);
					cntt++;
					qq[cntt]=d[i].jian;
				}
			}
		}
//		cout<<shua<<" "<<shub<<" "<<shuc<<"\n";
		if(shua>n/2){
			sort(q+1,q+1+cnt);
			for(int i=1;i<=shua-n/2;i++){
				ans-=q[i];
			}
		}
		if(shub>n/2){
			sort(qq+1,qq+1+cntt);
			for(int i=1;i<=shub-n/2;i++){
				ans-=qq[i];
			}
		}
		if(shuc>n/2){
			sort(qqq+1,qqq+1+cnttt);
			for(int i=1;i<=shuc-n/2;i++){
				ans-=qqq[i];
			}
		}
		cout<<ans<<"\n";
	}
}
//Ren5Jie4Di4Ling5%
