#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//freopen("club.in","stdin");
//freopen("club.out","stdout");
const int MAXX=1e5+5;
ll t,n;
struct st{
	int a,b,c;
	bool flag=false;
	int maxs=max(a,max(b,c));
};
int ca,cb,cc; 
st cnt[100005];
ll ans;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>cnt[i].a>>cnt[i].b>>cnt[i].c;
		}
		ans=0;
		ca=cb=cc=0;
		for(int i=1;i<=n;i++){
			if(cnt[i].a==cnt[i].maxs && cnt[i].flag==false && ca<=n/2){
				ans+=cnt[i].a;	
				cnt[i].flag=true;	
				ca++;
			}
		}
		for(int i=1;i<=n;i++){
			if(cnt[i].b==cnt[i].maxs && cnt[i].flag==false && cb<=n/2){
				ans+=cnt[i].b;				
				cb++;
				cnt[i].flag=true;
			}
		}
		for(int i=1;i<=n;i++){
			if(cnt[i].c==cnt[i].maxs && cnt[i].flag==false && cc<=n/2){
				ans+=cnt[i].c;				
				cc++;
				cnt[i].flag=true;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
