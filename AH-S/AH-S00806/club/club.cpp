#include<bits/stdc++.h>
using namespace std;
int t,n;
int zhaosheng[5];
struct ww{
	int first,cost;
};

bool cmp(ww x,ww y){
    return x.cost>y.cost;
}
int main(){
	freopen("club.in","r",stdin);

	freopen("club.out","w",stdout);
	cin>>t;
	for(int tt=1;tt<=t;tt++){
        vector<ww> s[5];
        ww bb;
        bb.cost=0,bb.first=0;
        s[1].push_back(bb);

        s[2].push_back(bb);

        s[3].push_back(bb);
        memset(zhaosheng,0,sizeof(zhaosheng));
		cin>>n;
		int a,b,c;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			int flag,maxn,cc;
			if(a>b&&a>c){
				flag=1;
				maxn=a;
				cc=max(b,c)-maxn;
			}else if(b>a&&b>c){
				flag=2;
				maxn=b;
				cc=max(a,c)-maxn;
			}else{
				flag=3;
				maxn=c;
				cc=max(a,b)-maxn;
			}
			ww aa;
			aa.first=maxn;
			aa.cost=cc;
			s[flag].push_back(aa);
			zhaosheng[flag]++;
		}
		int ans=0;
        for(int i=1;i<s[1].size();i++){
            ans+=s[1][i].first;
           // cout<<s[1][i].first<<'@';
        }//cout<<endl;
        for(int i=1;i<s[2].size();i++){
            ans+=s[2][i].first;//cout<<s[2][i].first<<' ';
        }//cout<<endl;
        for(int i=1;i<s[3].size();i++){
            ans+=s[3][i].first;//cout<<s[3][i].first<<' ';
        }//cout<<endl;
        ww sss[50005];

        if(zhaosheng[1]>(n/2)){
            for(int i=1;i<=s[1].size();i++){
                sss[i].cost=s[1][i].cost;
                sss[i].first=s[1][i].first;
            }
            sort(sss+1,sss+1+zhaosheng[1],cmp);
            for(int i=1;i<=zhaosheng[1]-n/2;i++){
                ans+=sss[i].cost;
            }
        }
        if(zhaosheng[2]>(n/2)){
            for(int i=1;i<=s[2].size();i++){
                sss[i].cost=s[2][i].cost;
                sss[i].first=s[2][i].first;
            }
            sort(sss+1,sss+1+zhaosheng[2],cmp);
            for(int i=1;i<=zhaosheng[2]-n/2;i++){
                ans+=sss[i].cost;
            }
        }
        if(zhaosheng[3]>(n/2)){
            for(int i=1;i<=s[3].size();i++){
                sss[i].cost=s[3][i].cost;
                sss[i].first=s[3][i].first;
            }
            sort(sss+1,sss+1+zhaosheng[3],cmp);
            for(int i=1;i<=zhaosheng[3]-n/2;i++){
                ans+=sss[i].cost;
            }
        }
		cout<<ans<<endl;
	}
	return 0;
}

