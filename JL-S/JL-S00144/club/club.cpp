#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
int t,n,cnt1,cnt2,cnt3,sp=1;
vector<int>a1(MAXN),a2(MAXN),a3(MAXN),p(MAXN);
int dfs(int p,int l){
    if (p==n){
        int tmp=0;
        if (cnt1<n/2)tmp=max(tmp,a1[p]);
        if (cnt2<n/2)tmp=max(tmp,a2[p]);
        if (cnt3<n/2)tmp=max(tmp,a3[p]);
        return tmp;
    }
    int tmp=0;
    if (cnt1<n/2){
        cnt1++;
        tmp=max(tmp,dfs(p+1,l+a1[p])+a1[p]);
        cnt1--;
    }
    if (cnt2<n/2){
        cnt2++;
        tmp=max(tmp,dfs(p+1,l+a2[p])+a2[p]);
        cnt2--;
    }
    if (cnt3<n/2){
        cnt3++;
        tmp=max(tmp,dfs(p+1,l+a3[p])+a3[p]);
        cnt3--;
    }
    return tmp;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        vector<int>ept(MAXN);
        a1=ept;
        a2=ept;
        a3=ept;
        p=ept;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a1[i]>>a2[i]>>a3[i];
            if (a2[i]!=0||a3[i]!=0)sp=0;
        }
        if (sp){
            sort(a1.begin()+1,a1.begin()+1+n);
            int ans=0;
            for (int i=0;i<n/2;i++){
                ans+=a1[n-i];
            }
            cout<<ans<<endl;
        }
        else{
            cout<<dfs(1,0)<<endl;
        }
    }
}
