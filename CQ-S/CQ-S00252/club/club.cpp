#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e4+5;
struct mm{
	int a,b,c;
}d[M];
int T;
int n,ans,sum1,sum2,sum3,x,y,z;
bool cmp(mm a,mm b){
	return max(a.a,max(a.b,a.c))>max(b.a,max(b.b,b.c));
}
void f(int i){
	if(d[i].a>d[i].b&&d[i].a>d[i].c){
			if(sum1+1<=n/2){
				sum1++,ans+=d[i].a,x=i;
				return;
			}
			else{
				if(d[x].b>d[x].c)ans+=d[x].b,sum2++,y=x;
				else ans+=d[i].c,sum3++,z=x;
				ans+=d[i].a-d[x].a;x=i;
			}
		}
	else if(d[i].b>d[i].a&&d[i].b>d[i].c){
			if(sum2+1<=n/2){
				sum2++,ans+=d[i].b,y=i;
				return;
			}
			else{
				if(d[x].a>d[x].c)ans+=d[y].a,sum1++,x=y;
				else ans+=d[i].c,sum3++,z=y;
				ans+=d[i].b-d[y].b;y=i;
			}
		}
	else if(d[i].c>d[i].b&&d[i].c>d[i].a){
		if(sum3+1<=n/2){
			sum3++,ans+=d[i].c,z=i;
			return;
		}
		else{
			if(d[x].a>d[x].b)ans+=d[z].a,sum1++,x=z;
			else ans+=d[i].b,sum2++,y=z;
			ans+=d[i].c-d[z].c;z=i;
		}
	}
}
signed main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=sum1=sum2=sum3=0;
		for(int i=1;i<=n;i++)cin>>d[i].a>>d[i].b>>d[i].c;
		sort(d+1,d+1+n,cmp);
		for(int i=1;i<=n;i++)f(i);
		cout<<ans<<"\n";
	}
	return 0;
}

