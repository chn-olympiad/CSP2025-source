#include<bits/stdc++.h>
using namespace std;
struct students_frog{
    int a1_frog,a2_frog,a3_frog,m1_frog,m2_frog,m3_frog;
}s_frog[114514];
int asort_frog[3];
int dp_frog[1145][1145];
int dpsp_frog[114514];
bool cmpm1_frog(students_frog x,students_frog y){return x.m1_frog>y.m1_frog;}
bool cmpm2_frog(students_frog x,students_frog y){return x.m2_frog>y.m2_frog;}
bool cmpm3_frog(students_frog x,students_frog y){return x.m3_frog>y.m3_frog;}
int main(){
    ios::sync_with_stdio(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t_frog;
    cin>>t_frog;
    while(t_frog--){
        int n_frog;
        cin>>n_frog;
        bool spa_frog=1,spb_frog=1;
        for(int i_frog=1;i_frog<=n_frog;i_frog++){
            cin>>s_frog[i_frog].a1_frog>>s_frog[i_frog].a2_frog>>s_frog[i_frog].a3_frog;
            if(s_frog[i_frog].a3_frog!=0){
                spa_frog=0;
                spb_frog=0;
            }
            if(s_frog[i_frog].a2_frog!=0){
                spa_frog=0;
            }
            asort_frog[0]=s_frog[i_frog].a1_frog;
            asort_frog[1]=s_frog[i_frog].a2_frog;
            asort_frog[2]=s_frog[i_frog].a3_frog;
            sort(asort_frog,asort_frog+3);
            s_frog[i_frog].m1_frog=asort_frog[2];
            s_frog[i_frog].m2_frog=asort_frog[1];
            s_frog[i_frog].m3_frog=asort_frog[0];
        }
        if(n_frog<1145){
            for(int j_frog=0;j_frog<=n_frog;j_frog++){
                for(int k_frog=0;k_frog<=n_frog;k_frog++){
                    dp_frog[j_frog][k_frog]=0;
                }
            }
            int ans_frog=0;
            for(int i_frog=1;i_frog<=n_frog;i_frog++){
                for(int i1_frog=n_frog/2;i1_frog>=0;i1_frog--){
                    for(int i2_frog=n_frog/2;i2_frog>=0;i2_frog--){
                        int i3_frog=i_frog-i1_frog-i2_frog;
                        if(i3_frog>n_frog/2) break;
                        if(i3_frog<0) continue;
                        dp_frog[i1_frog][i2_frog]=max(max((i1_frog>=1?dp_frog[i1_frog-1][i2_frog]+s_frog[i_frog].a1_frog:-0x3f3f3f3f),(i2_frog>=1?dp_frog[i1_frog][i2_frog-1]+s_frog[i_frog].a2_frog:-0x3f3f3f3f)),(i3_frog>=1?dp_frog[i1_frog][i2_frog]+s_frog[i_frog].a3_frog:-0x3f3f3f3f));
                        ans_frog=max(ans_frog,dp_frog[i1_frog][i2_frog]);
                    }
                }
            }
            cout<<ans_frog<<endl;
        }
        else if(spa_frog||spb_frog){
            for(int k_frog=0;k_frog<=n_frog;k_frog++){
                dpsp_frog[k_frog]=0;
            }
            int ans_frog=0;
            for(int i_frog=1;i_frog<=n_frog;i_frog++){
                for(int i1_frog=n_frog/2;i1_frog>=0;i1_frog--){
                    int i2_frog=i_frog-i1_frog;
                    if(i2_frog>n_frog/2) break;
                    if(i2_frog<0) continue;
                    dpsp_frog[i1_frog]=max((i1_frog>=1?dpsp_frog[i1_frog-1]+s_frog[i_frog].a1_frog:-0x3f3f3f3f),(i2_frog>=1?dpsp_frog[i1_frog]+s_frog[i_frog].a2_frog:-0x3f3f3f3f));
                    ans_frog=max(ans_frog,dpsp_frog[i1_frog]);
                }
            }
            cout<<ans_frog<<endl;
        }
        else{
            int cnt_frog[3]={0,0,0};
            sort(s_frog+1,s_frog+n_frog+1,cmpm3_frog);
            sort(s_frog+1,s_frog+n_frog+1,cmpm2_frog);
            sort(s_frog+1,s_frog+n_frog+1,cmpm1_frog);
            int ans_frog=0;
            for(int i_frog=1;i_frog<=n_frog;i_frog++){
                int i1_frog,i2_frog,i3_frog;
                if(s_frog[i_frog].a1_frog==s_frog[i_frog].m1_frog) i1_frog=1;
                if(s_frog[i_frog].a1_frog==s_frog[i_frog].m2_frog) i1_frog=2;
                if(s_frog[i_frog].a1_frog==s_frog[i_frog].m3_frog) i1_frog=3;
                if(s_frog[i_frog].a2_frog==s_frog[i_frog].m1_frog) i2_frog=1;
                if(s_frog[i_frog].a2_frog==s_frog[i_frog].m2_frog) i2_frog=2;
                if(s_frog[i_frog].a2_frog==s_frog[i_frog].m3_frog) i2_frog=3;
                if(s_frog[i_frog].a3_frog==s_frog[i_frog].m1_frog) i3_frog=1;
                if(s_frog[i_frog].a3_frog==s_frog[i_frog].m2_frog) i3_frog=2;
                if(s_frog[i_frog].a3_frog==s_frog[i_frog].m3_frog) i3_frog=3;
                if(cnt_frog[i1_frog-1]<n_frog/2){
                    ans_frog+=s_frog[i_frog].m1_frog;
                    cnt_frog[i1_frog-1]++;
                }
                else if(cnt_frog[i2_frog-1]<n_frog/2){
                    ans_frog+=s_frog[i_frog].m2_frog;
                    cnt_frog[i2_frog-1]++;
                }
                if(cnt_frog[i3_frog-1]<n_frog/2){
                    ans_frog+=s_frog[i_frog].m3_frog;
                    cnt_frog[i3_frog-1]++;
                }
            }
            cout<<ans_frog<<endl;
        }
    }
    return 0;
}