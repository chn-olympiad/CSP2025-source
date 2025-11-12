#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q;
string last[N],now[N];
bool isson(string a,string b){
    if(a.size()>b.size()){
        return false;
    }
    for(int s=0;s+a.size()-1<b.size();s++){
        bool flag=true;
        for(int i=s;i<=s+a.size()-1;i++){
            if(a[i-s]!=b[i]){
                flag=false;
            }
        }
        if(flag){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen(:"replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>last[i]>>now[i];
    }

    while(q--){
        string a,b;
        cin>>a>>b;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(isson(last[i],a)&&isson(now[i],b)){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
