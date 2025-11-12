#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int n,sum,T,ca,cb,cc,wa[N],wb[N],wc[N],cd[N],tot;
struct Node{
	int a,b,c;
}w[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ca=cb=cc=tot=0;sum=0;
		for(int i=1;i<=n;i++){
			cin>>w[i].a>>w[i].b>>w[i].c;
			sum+=max({w[i].a,w[i].b,w[i].c});
			if(w[i].a>w[i].b&&w[i].a>w[i].c) wa[++ca]=i;
			else if(w[i].b>w[i].a&&w[i].b>w[i].c) wb[++cb]=i;
			else wc[++cc]=i;
		}
		if(ca<=n/2&&cb<=n/2&&cc<=n/2){
			cout<<sum<<'\n';
		}else{
			for(int i=1;i<=n;i++){
				if(w[i].a>w[i].b&&w[i].a>w[i].c){
					if(ca>n/2) cd[++tot]=w[i].a-max(w[i].b,w[i].c);
				}else if(w[i].b>w[i].a&&w[i].b>w[i].c){
					if(cb>n/2) cd[++tot]=w[i].b-max(w[i].a,w[i].c);
				}else{
					if(cc>n/2) cd[++tot]=w[i].c-max(w[i].b,w[i].a);
				}
			}
			sort(cd+1,cd+tot+1);
			for(int i=1;i<=max({ca,cb,cc})-n/2;i++) sum-=cd[i];
			cout<<sum<<'\n';
		}
	}
	return 0;
}
