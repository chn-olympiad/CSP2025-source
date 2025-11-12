#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace zzy{
	const int maxn=1e5+10;
	int T,n,lim;
	int ans;
	struct node{
		int val,id;
		bool operator < (const node &it)const{
			return val>it.val; 
		}
	}s[maxn][3];
	int cnt[3];
	int a[maxn],len;
	void clear(){
		cnt[0]=cnt[1]=cnt[2]=0;
		len=ans=0;
	}
	int main(){
		cin>>T;
		while(T--){
			clear();
			cin>>n;
			for(int i=1;i<=n;i++){
				for(int k=0;k<3;k++)cin>>s[i][k].val,s[i][k].id=k;
				sort(s[i],s[i]+3);
				cnt[s[i][0].id]++;
				ans+=s[i][0].val;
			}
			lim=n/2;
			if(cnt[0]<=lim&&cnt[1]<=lim&&cnt[2]<=lim){cout<<ans<<'\n';continue ;}
			int x;
			if(cnt[0]>lim)x=0;
			else if(cnt[1]>lim)x=1;
			else x=2;
			for(int i=1;i<=n;i++){
				if(s[i][0].id!=x)continue ;
				a[++len]=s[i][1].val-s[i][0].val;
			}
			sort(a+1,a+len+1,greater<int>());
			for(int i=1;i<=cnt[x]-lim;i++)ans+=a[i];
			cout<<ans<<'\n';
		} 

		return 0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	zzy::main();
	return 0;
}
/*
时代少年团我们喜欢你 
*/
