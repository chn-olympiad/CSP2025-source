#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int love[3];
};
int dir[3][2]={{1,2},{0,2},{0,1}};
int mode;
bool cmp(node x,node y){
    int ex=max(x.love[dir[mode][0]],x.love[dir[mode][1]])-x.love[mode];
    int ey=max(y.love[dir[mode][0]],y.love[dir[mode][1]])-y.love[mode];
    return ex<ey;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<node>s[3];
        for(int i=1;i<=n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(a>=b&&a>=c){
                s[0].push_back({{a,b,c}});
            }
            if(b>=a&&b>=c){
                s[1].push_back({{a,b,c}});
            }
            if(c>=a&&c>=b){
                s[2].push_back({{a,b,c}});
            }
        }
        for(int i=0;i<3;i++){
            if(s[i].size()>n/2){
                mode=i;
                sort(s[i].begin(),s[i].end(),cmp);
                while(s[i].size()>n/2){
                    if(s[i][s[i].size()-1].love[dir[i][0]]>s[i][s[i].size()-1].love[dir[i][1]]){
                        s[dir[i][0]].push_back(s[i][s[i].size()-1]);
                    }
                    else{
                        s[dir[i][1]].push_back(s[i][s[i].size()-1]);
                    }
                    s[i].pop_back();
                }
                break;
            }
        }
        int ans=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<s[i].size();j++){
                ans+=s[i][j].love[i];
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
