#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct cl{
	int v1,v2,v3;
}a[100005];
bool cmp1(cl x,cl y){
	return x.v1>y.v1;
}
bool cmp2(cl x,cl y){
	return x.v2>y.v2;
}
int vis[100005];
int ans=0,sum=-1;
int cnt1=0,cnt2=0,cnt3=0;
void dfs(int k){
    if(k==n+1){
        sum=max(sum,ans);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            if(cnt1<n/2){
                ans+=a[i].v1;
                cnt1++;
                dfs(k+1);
                cnt1--;
                ans-=a[i].v1;
            }
            if(cnt2<n/2){
                ans+=a[i].v2;
                cnt2++;
                dfs(k+1);
                cnt2--;
                ans-=a[i].v2;
            }
            if(cnt3<n/2){
                ans+=a[i].v3;
                cnt3++;
                dfs(k+1);
                cnt3--;
                ans-=a[i].v3;
            }
            vis[i]=0;
        }
    }
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int s1=0,s2=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].v1>>a[i].v2>>a[i].v3;
			a[i].bh=i;
			s1+=a[i].v2+a[i].v3;
			s2+=a[i].v3;
		}
		if(s1==0){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].v1+a[i].v2;
			}
			cout<<ans<<endl;
			continue;
		}
		if(s2==0&&n==100000){
            int mx1=0,mx2=0;
            for(int i=1;i<=n;i++){
                mx1+=a[i].v1;
                mx2+=a[i].v2;
            }
            for(int i=1;i<=n;i++){
                if(mx1-a[i].v1<mx2-a[i].v2){
                    mx2-=a[i].v2;
                }else mx1-=a[i].v1;
            }
			cout<<mx1+mx2<<endl;
			continue;
		}
		sum=-1;
		dfs(1);
		cout<<sum<<endl;
	}
	return 0;
}
