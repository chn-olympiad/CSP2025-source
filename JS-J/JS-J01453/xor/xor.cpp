#include <bits/stdc++.h>
using namespace std;
#define int long long
int twoupn[]={1048576,524288,262144,131072,65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1};
string ten2two(int x){
    string ans;
    for(int i=0;i<=20;i++){
        if(x-twoupn[i]>=0){
            x-=twoupn[i];
            ans+='1';
        }else{
            ans+='0';
        }
    }
    return ans;
}
int two2ten(string x){
    int ans=0;
    for(int i=0;i<=20;i++){
        ans+=(x[i]-'0')*twoupn[i];
    }
    return ans;
}
int Xor(int a,int b){
    string b_a=ten2two(a),b_b=ten2two(b),ans;
    for(int i=0;i<=20;i++){
        if(b_a[i]!=b_b[i]){
            ans+='1';
        }else{
            ans+='0';
        }
    }
    return two2ten(ans);
}
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,nowx,nowr,cnt=0,a[500010];
    pair<int,int> rec;
    vector<pair<int,int> > kqj;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1;l<=n;l++){
        nowx=a[l];
        if(nowx==k){
            rec.first=rec.second=l;
            kqj.emplace_back(rec);
            continue;
        }
        for(int r=l+1;r<=n;r++){
            nowx=Xor(nowx,a[r]);
            if(nowx==k){
                rec.first=l;
                rec.second=r;
                kqj.emplace_back(rec);
                break;
            }
        }
    }
    if(kqj.size()==0){
        cout<<0;
        return 0;
    }
    sort(kqj.begin(),kqj.end(),cmp);
    nowr=kqj[0].second;
    cnt++;
    for(int i=1;i<kqj.size();i++){
        if(kqj[i].first>nowr){
            cnt++;
            nowr=kqj[i].second;
        }
    }
    cout<<cnt;
    return 0;
}
