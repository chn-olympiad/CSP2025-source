#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,sum1=0,sum2=0,sum3=0,s[N][4],a[N],b[N],c[N],ans=0,T,ans2;
struct KKK{
	int na,va;
}k[N];
void dfs(int x,int sa,int sb,int sc,int now){
	if(x>n){
		return;
	}
	if(sa>0){
		ans=max(ans,now+s[x][1]);
		dfs(x+1,sa-1,sb,sc,now+s[x][1]);
	}
	if(sb>0){
		ans=max(ans,now+s[x][2]);
		dfs(x+1,sa,sb-1,sc,now+s[x][2]);
	}
	if(sc>0){
		ans=max(ans,now+s[x][3]);
		dfs(x+1,sa,sb,sc-1,now+s[x][3]);
	}
	return;
}
bool cmp(KKK a,KKK b){
	return a.va>b.va;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		bool pdA=1,pdB=1;
		ans=0;
		ans2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i][1]>>s[i][2]>>s[i][3];
			ans2+=max(s[i][1],max(s[i][2],s[i][3]));
			a[i]=s[i][1];
			k[i].va=s[i][1]-s[i][2];
			if(k[i].va<0){
				k[i].va=-1*k[i].va;
			}
			k[i].na=i;
//			b[i]=s[i][2];
//			c[i]=s[i][3];
			if(s[i][2]!=0||s[i][3]!=0){
				pdA=0;
			}
			if(s[i][3]!=0){
				pdB=0;
			}
		}
		if(pdA){
			sort(a+1,a+1+n);
			for(int i=n;i>n/2;i--){
				ans+=a[i];
			}
		}else if(pdB){
			sort(k+1,k+1+n,cmp);
			for(int i=1;i<=n;i++){
				ans+=max(s[k[i].na][1],s[k[i].na][2]);
			} 
			
		}else if(n>200){
			cout<<ans2<<endl;
			continue;
		}else{
			dfs(1,n/2,n/2,n/2,0);
		}
		cout<<ans<<endl;	
	}
	return 0;
} 
