#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> a1(100100);
vector<int> a2(100100);
vector<int> a3(100100);
vector<int> c1;vector<int> c2;vector<int> c3;
bool cmp1(int a,int b){
    return min(a1[a]-a2[a],a1[a]-a3[a])>min(a1[b]-a2[b],a1[b]-a3[b]);
}
bool cmp2(int a,int b){
    return min(a2[a]-a1[a],a2[a]-a3[a])>min(a2[b]-a1[b],a2[b]-a3[b]);
}
bool cmp3(int a,int b){
    return min(a3[a]-a1[a],a3[a]-a2[a])>min(a3[b]-a1[b],a3[b]-a2[b]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    int ans=0;
    while(t--){
        a1.clear();a2.clear();a3.clear();c1.clear();c2.clear();c3.clear();
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a1[i]>>a2[i]>>a3[i];
            if(a1[i]>=max(a2[i],a3[i])){
                ans+=a1[i];c1.push_back(i);
            }
            else if(a2[i]>=max(a1[i],a3[i])){
                ans+=a2[i];c2.push_back(i);
            }
            else if(a3[i]>=max(a1[i],a2[i])){
                ans+=a3[i];c3.push_back(i);
            }
        }
        if(c1.size()>n/2){
            sort(c1.begin(),c1.end(),cmp1);
            for(int i=c1.size()-1;i>=n/2;i--){
                ans-=min(a1[c1[i]]-a2[c1[i]],a1[c1[i]]-a3[c1[i]]);
            }
        }
        if(c2.size()>n/2){
            sort(c2.begin(),c2.end(),cmp2);
            for(int i=c2.size()-1;i>=n/2;i--){
                ans-=min(a2[c2[i]]-a1[c2[i]],a2[c2[i]]-a3[c2[i]]);
            }
        }
        if(c3.size()>n/2){
            sort(c3.begin(),c3.end(),cmp3);
            for(int i=c3.size()-1;i>=n/2;i--){
                ans-=min(a3[c3[i]]-a1[c3[i]],a3[c3[i]]-a2[c3[i]]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//DE BG6CNI
//251101UTC0710
