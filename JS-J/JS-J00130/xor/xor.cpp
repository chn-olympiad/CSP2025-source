#include<bits/stdc++.h>
using namespace std;
int n,k,len,len2,i;

bool check(vector<int>a){
    //cout<<s<<endl;
    len2=a.size();
    int ans=a.front();
    for(i=1;i<len2;i++){
        ans=ans^a[i];
    }
    //cout<<ans;
    return (k==ans);
}
vector<int> sub(vector<int>a,int start,int siz){
    vector<int>b;
    for(int i=start;i<start+siz;i++){
        b.push_back(a[i]);
    }
    return b;
}
int dfs(int siz,vector<int>a,int ans){
    vector<int>id;
    int len=a.size();
    if(siz>len||len==0){
        return 0;
    }
    id.push_back(0);
    for(int i=0;i<n-siz+1;i++)
    {
        if(check(sub(a,i,siz))){
            id.push_back(i-1);
            id.push_back(i+siz);
            ans++;
            //cout<<siz<<" "<<i<<endl;
        }
    }
    id.push_back(len-1);

    while(!id.empty()){
        int d=id.back();
        id.pop_back();
        int c=id.back();
        id.pop_back();
        ans+=dfs(siz+1,sub(a,c,d-c+1),0);
    }
    return ans;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    vector<int>a;
    scanf("%d%d",&n,&k);

    for(int i=0,x;i<n;i++){
        scanf("%d",&x);
        a.push_back(x);
    }
    cout<<dfs(1,a,0);
    return 0;
}
