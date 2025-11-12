#include <bits/stdc++.h>
using namespace std;

struct node{
    int a,b,c,m;
}a[100001];

void solve();
bool cmp(node,node);
bool cmp1(node,node);
bool cmp2(node,node);

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}

inline bool cmp(node a,node b){
    if(a.a!=b.a)
        return a.a>b.a;
    else if(a.b!=b.b)
        return a.b>b.b;
    else
        return a.c>b.c;
}

inline bool cmp1(node a,node b){
	if(a.m==a.a&&b.m==b.a)
		return a.a>b.a;
	else if(a.m==a.a)
		return true;
	return false;
}

inline bool cmp2(node a,node b){
	return a.a>b.a;
}

inline void solve(){
    int n,ax=0,bx=0,cx=0,cm=0,bm=0;
	long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b>>a[i].c;
        a[i].m=max(max(a[i].a,a[i].b),a[i].c);
        cm=max(cm,a[i].c);
        bm=max(bm,a[i].b);
	}
    if(cm==0){
    	sort(a+1,a+n+1,cmp1);
    	for(int i=1;i<=n;i++)
    		if(i<=n/2)
    			ans+=a[i].a;
    		else
    			ans+=a[i].b;
    	cout<<ans<<endl;
    	return;
	}
	if(cm==0&&bm==0){
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n/2;i++)
			ans+=a[i].a;
		cout<<ans<<endl;
		return;
	}
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
    	if(a[i].m==a[i].a){
    		if(ax<n/2){
    			ax++;
    			ans+=a[i].m;
    		}
    		else if(a[i].b>a[i].c){
    			bx++;
    			ans+=a[i].b;
			}
			else{
				cx++;
				ans+=a[i].c;
			}
		}
		else if(a[i].m==a[i].b){
    		if(bx<n/2){
    			bx++;
    			ans+=a[i].m;
    		}
    		else if(a[i].a>a[i].c){
    			ax++;
    			ans+=a[i].a;
			}
			else{
				cx++;
				ans+=a[i].c;
			}
		}
		else{
    		if(cx<n/2){
    			cx++;
    			ans+=a[i].m;
    		}
    		else if(a[i].a>a[i].b){
    			ax++;
    			ans+=a[i].a;
			}
			else{
				cx++;
				ans+=a[i].c;
			}
		}
	}
	cout<<ans<<endl;
    return;
}
