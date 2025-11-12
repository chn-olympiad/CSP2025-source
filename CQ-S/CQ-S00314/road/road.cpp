#include<bits/stdc++.h>
using namespace std;
struct edge_frog{
    long long u_frog,v_frog,w_frog;
}e_frog[1919810+114514],e1_frog[1919810+114514];
long long cnt_frog=0,cnt1_frog=0;
bool cmpew_frog(edge_frog a_frog,edge_frog b_frog){
    return a_frog.w_frog<b_frog.w_frog;
}
long long k_frog;
long long s_frog[11451],s1_frog[11451];
long long c_frog[14],a_frog[14][11451];
bool cc_frog[14];
long long find_frog(long long x_frog){
    return (s_frog[x_frog]==x_frog)?x_frog:s_frog[x_frog]=find_frog(s_frog[x_frog]);
}
void merge_frog(long long x_frog,long long y_frog){
    s_frog[find_frog(x_frog)]=find_frog(y_frog);
}
long long find1_frog(long long x_frog){
    return (s1_frog[x_frog]==x_frog)?x_frog:s1_frog[x_frog]=find_frog(s1_frog[x_frog]);
}
void merge1_frog(long long x_frog,long long y_frog){
    s1_frog[find_frog(x_frog)]=find_frog(y_frog);
}
int main(){
    ios::sync_with_stdio(0);
    
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    long long n_frog,m_frog,k_frog;
    bool spa_frog=1,spkis0_frog=0;
    cin>>n_frog>>m_frog>>k_frog;
    for(long long i_frog=1;i_frog<=n_frog;i_frog++){
        s_frog[i_frog]=i_frog;
    }
    if(k_frog==0) spkis0_frog=1;
    long long ul_frog,vl_frog,wl_frog;
    for(long long i_frog=1;i_frog<=m_frog;i_frog++){
        cin>>ul_frog>>vl_frog>>wl_frog;
        e_frog[++cnt_frog]={ul_frog,vl_frog,wl_frog};
        merge_frog(ul_frog,vl_frog);
        e1_frog[++cnt1_frog]={ul_frog,vl_frog,wl_frog};
        merge1_frog(ul_frog,vl_frog);
    }
    for(long long i_frog=1;i_frog<=k_frog;i_frog++){
        cin>>c_frog[i_frog];
        if(c_frog[i_frog]!=0) spa_frog=0;
        for(long long j_frog=1;j_frog<=n_frog;j_frog++){
            cin>>a_frog[i_frog][j_frog];
        }
    }
    if(spkis0_frog){
        sort(e_frog+1,e_frog+cnt_frog+1,cmpew_frog);
        long long ans_frog=0;
        for(long long i_frog=1,ccnt_frog=1;i_frog<=cnt_frog&&ccnt_frog<=n_frog-1;i_frog++){
            if(find_frog(e_frog[i_frog].u_frog)!=find_frog(e_frog[i_frog].v_frog)){
                ccnt_frog++;
                ans_frog+=e_frog[i_frog].w_frog;
            }
        }
        cout<<ans_frog;
    }
    
    else if(spa_frog){
        long long cntofc_frog=0;
        for(long long i_frog=1;i_frog<=k_frog;i_frog++){
            for(long long j_frog=1;j_frog<=n_frog;j_frog++){
                e_frog[++cnt_frog]={i_frog+n_frog,j_frog+n_frog,a_frog[i_frog][j_frog]};
                merge_frog(i_frog+n_frog,j_frog+n_frog);
            }
        }
        sort(e_frog+1,e_frog+cnt_frog+1,cmpew_frog);
        long long ans_frog=0;
        for(long long i_frog=1,ccnt_frog=1;i_frog<=cnt_frog&&ccnt_frog<=n_frog+cntofc_frog-1;i_frog++){
            if(find_frog(e_frog[i_frog].u_frog)!=find_frog(e_frog[i_frog].v_frog)){
                if(e_frog[i_frog].u_frog>n_frog){
                    if(cc_frog[e_frog[i_frog].u_frog]==0){
                        cntofc_frog++;
                        cc_frog[e_frog[i_frog].u_frog]=1;
                    }
                }
                if(e_frog[i_frog].v_frog>n_frog){
                    if(cc_frog[e_frog[i_frog].v_frog]==0){
                        cntofc_frog++;
                        cc_frog[e_frog[i_frog].v_frog]=1;
                    }
                }
                ccnt_frog++;
                ans_frog+=e_frog[i_frog].w_frog;
            }
        }
        cout<<ans_frog;
    }
    
    else{
        long long ans_frog=0;
        long long cntofc_frog=0;
        long long mn_frog=0x7f7f7f7f;
        for(long long i_frog=0;i_frog<(1<<k_frog);i_frog++){
            ans_frog=0;cntofc_frog=0;
            cnt_frog=cnt1_frog;
            for(long long k_frog=1;k_frog<=n_frog;k_frog++){
                s_frog[k_frog]=s1_frog[k_frog];
            }
            long long i1_frog=i_frog;
            for(long long j_frog=1;j_frog<=k_frog;j_frog++){
                bool w_frog=i1_frog&1;
                /*cout<<w_frog;*/
                i1_frog>>=1;
                if(w_frog){
                    cntofc_frog++;
                    ans_frog+=c_frog[j_frog];
                    for(long long k_frog=1;k_frog<=n_frog;k_frog++){
                        e_frog[++cnt_frog]={j_frog+n_frog,k_frog+n_frog,a_frog[j_frog][k_frog]};
                        merge_frog(i_frog+n_frog,j_frog+n_frog);
                    }
                }
            }
            /*cout<<ans_frog<<endl;*/
            sort(e_frog+1,e_frog+cnt_frog+1,cmpew_frog);
            for(long long i_frog=1,ccnt_frog=1;i_frog<=cnt_frog&&ccnt_frog<=n_frog+cntofc_frog-1;i_frog++){
                if(find_frog(e_frog[i_frog].u_frog)!=find_frog(e_frog[i_frog].v_frog)){
                    ccnt_frog++;
                    ans_frog+=e_frog[i_frog].w_frog;
                    //if(ans_frog>=mn_frog)break;
                    /*cout<<e_frog[i_frog].u_frog<<e_frog[i_frog].v_frog<<endl;*/
                }
            }
            mn_frog=min(mn_frog,ans_frog);
        }
        cout<<mn_frog;
    }
    return 0;
}