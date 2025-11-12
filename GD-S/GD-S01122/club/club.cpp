//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
using namespace std;
struct rr{
	int n,m;
	operator<(rr x)const{
		return m>x.m;
	}
};
priority_queue<rr> q;
int pp,n;
int s[100100][5];
int pd[5];
int mx[100100],ml[100100],mmx[100100];
long long ans=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>pp;
	while(pp--){
		cin>>n;
		for(int i=1;i<=n;i++){
			mx[i]=-5000,ml[i],mmx[i]=-5000;
			for(int o=1;o<=3;o++){
				cin>>s[i][o];
				if(s[i][o]>mx[i]){
					mmx[i]=mx[i];
					mx[i]=s[i][o];
					ml[i]=o;
				}
				else if(s[i][o]>mmx[i]){
					mmx[i]=s[i][o];
//					mml=o;
				}
			}
			ans=ans+s[i][ml[i]];
			pd[ml[i]]++;
		}
		int op;
		if(pd[1]>pd[2])op=1;
		else op=2;
		if(pd[3]>pd[op])op=3;
		for(int i=1;i<=n;i++){
			if(ml[i]==op){
				q.push({i,mx[i]-mmx[i]});
			}
		}
		while(pd[op]>(n/2)){
			int u=q.top().m;
			q.pop();
			ans=ans-u;
			pd[op]--;
		}
		while(!q.empty())q.pop();
		cout<<ans<<endl;
		ans=0;pd[1]=pd[2]=pd[3]=0;
	}
	return 0;
}
