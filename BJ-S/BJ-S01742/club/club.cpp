#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,res=INT_MIN;

struct node{
    int a1,a2,a3,cha;
};

bool cmp(node &xx,node &yy){
    return xx.a1>yy.a1;
}

bool cmp2(node &xx,node &yy){
    return xx.cha>yy.cha;
}
void dfs(int maxx,int now,int one,int two,int three,int ans,vector<vector<int> >&a){
	if(one+two+three==n){
		res=max(res,ans);
		return;
	}

	if(one<maxx) dfs(maxx,now+1,one+1,two,three,ans+a[now][1],a);
	if(two<maxx) dfs(maxx,now+1,one,two+1,three,ans+a[now][2],a);
	if(three<maxx) dfs(maxx,now+1,one,two,three+1,ans+a[now][3],a);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t;

	cin>>t;

	while(t--){
		cin>>n;

        bool f1=true,f2=true;
		vector<vector<int> >a(n+1,vector<int>(4,0));
        vector<node>v(n+1,{0,0,0,0});

		for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            v[i].a1=a[i][1];
            v[i].a2=a[i][2];
            v[i].a3=a[i][3];
            v[i].cha=a[i][1]-a[i][2];

            if(a[i][2]!=0) f1=false;
            if(a[i][3]!=0) f2=false;
		}

        int ans=0;

        if(f1&&f2){
            sort(v.begin()+1,v.end(),cmp);
            for(int i=1;i<=n/2;i++) ans+=v[i].a1;
            cout<<ans<<endl;
            continue;
        }else if(!f1&&f2){
            sort(v.begin()+1,v.end(),cmp2);
            for(int i=1;i<=n/2;i++) ans+=v[i].a1;
            for(int i=n/2+1;i<=n;i++) ans+=v[i].a2;
            cout<<ans<<endl;
            continue;
        }

        res=INT_MIN;

		dfs(n/2,1,0,0,0,0,a);

		cout<<res<<endl;

	}
}
