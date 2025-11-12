#include<bits/stdc++.h>
using namespace std;
struct xxs{
    int hao[3];
    int topp[3];
};
xxs a[100010];
int n;
int c[3][100010], m[3];
bool cmp(int i, int j){
    return (a[i].hao[a[i].topp[0]]-a[i].hao[a[i].topp[1]])<(a[j].hao[a[j].topp[0]]-a[j].hao[a[j].topp[1]]);
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin>>T;
    while(T--){
        m[0]=m[1]=m[2]=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].hao[0]>>a[i].hao[1]>>a[i].hao[2];
            pair<int, int> ls[3];
            ls[0]={a[i].hao[0], 0};
            ls[1]={a[i].hao[1], 1};
            ls[2]={a[i].hao[2], 2};
            sort(ls, ls+3);
            a[i].topp[0]=ls[2].second;
            a[i].topp[1]=ls[1].second;
            a[i].topp[2]=ls[0].second;
            m[a[i].topp[0]]++;
            c[a[i].topp[0]][m[a[i].topp[0]]]=i;
        }
        int foc=-1;
        for(int i=0;i<3;i++){
            if(m[i]>n/2){
                foc=i;
            }
        }
        long long ans=0;
        if(foc!=-1){
            sort(c[foc]+1, c[foc]+m[foc]+1, cmp);
            for(int i=1;i<=m[foc]-n/2;i++){
                ans+=(a[c[foc][i]].hao[a[c[foc][i]].topp[1]]-a[c[foc][i]].hao[a[c[foc][i]].topp[0]]);
            }
        }
        for(int k=0;k<3;k++){
            for(int i=1;i<=m[k];i++){
                ans+=a[c[k][i]].hao[k];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}