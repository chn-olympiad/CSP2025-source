#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int v,id;
    node(){}
    node(int vv,int ii){v=vv,id=ii;}
};
int t,n,a[100010][5];
bool cmp(node x,node y){return x.v>y.v;}
signed main(){
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        vector<int> id1,id2,id3;
        cin>>n;int num1=0,num2=0,num3=0,ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];ans+=max({a[i][1],a[i][2],a[i][3]});
            if(max({a[i][1],a[i][2],a[i][3]})==a[i][1])
                num1++,id1.push_back(i);
            else if(max({a[i][1],a[i][2],a[i][3]})==a[i][2])
                num2++,id2.push_back(i);
            else
                num3++,id3.push_back(i);
        }
        if(max({num1,num2,num3})<=n/2)
            cout<<ans<<"\n";
        else if(max({num1,num2,num3})==num1){
            vector<node> s;vector<int> vis(n+10,0);
            for(int i=0;i<num1;i++)
                s.push_back(node(a[id1[i]][2]-a[id1[i]][1],id1[i])),s.push_back(node(a[id1[i]][3]-a[id1[i]][1],id1[i]));
            sort(s.begin(),s.end(),cmp);
            for(int i=0,num=num1;i<s.size()&&num>n/2;i++)
                if(!vis[s[i].id])
                    ans+=s[i].v,num--,vis[s[i].id]=1;
            cout<<ans<<"\n";
        }else if(max({num1,num2,num3})==num2){
            vector<node> s;vector<int> vis(n+10,0);
            for(int i=0;i<num2;i++)
                s.push_back(node(a[id2[i]][1]-a[id2[i]][2],id2[i])),s.push_back(node(a[id2[i]][3]-a[id2[i]][2],id2[i]));
            sort(s.begin(),s.end(),cmp);
            for(int i=0,num=num2;i<s.size()&&num>n/2;i++)
                if(!vis[s[i].id])
                    ans+=s[i].v,num--,vis[s[i].id]=1;
            cout<<ans<<"\n";
        }else{
            vector<node> s;vector<int> vis(n+10,0);
            for(int i=0;i<num3;i++)
                s.push_back(node(a[id3[i]][1]-a[id3[i]][3],id3[i])),s.push_back(node(a[id3[i]][2]-a[id3[i]][3],id3[i]));
            sort(s.begin(),s.end(),cmp);
            for(int i=0,num=num3;i<s.size()&&num>n/2;i++)
                if(!vis[s[i].id])
                    ans+=s[i].v,num--,vis[s[i].id]=1;
            cout<<ans<<"\n";
        }
    }
    return 0;
}