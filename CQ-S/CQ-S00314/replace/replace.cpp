#include<bits/stdc++.h>
using namespace std;
struct aa_frog{
    int p_frog,l_frog;
}p_frog[114514*2];
int pp_frog[114514*2];
bool cmp_frog(aa_frog a_frog,aa_frog b_frog){return a_frog.p_frog<b_frog.p_frog;}
int main(){
    ios::sync_with_stdio(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n_frog,q_frog;
    cin>>n_frog>>q_frog;
    string a_frog,b_frog;
    for(int i_frog=1;i_frog<=n_frog;i_frog++){
        cin>>a_frog>>b_frog;
        p_frog[i_frog].p_frog=a_frog.find("b")-b_frog.find("b");
        p_frog[i_frog].l_frog=a_frog.size();
        pp_frog[i_frog]=p_frog[i_frog].p_frog;
    }
    sort(p_frog+1,p_frog+n_frog+1,cmp_frog);
    sort(pp_frog+1,pp_frog+n_frog+1);
    while(q_frog--){
        cin>>a_frog>>b_frog;
        int lp=a_frog.find("b")-b_frog.find("b");
        int s_frog=a_frog.size();
        int cnt_frog=0;
        for(int i_frog=lower_bound(pp_frog+1,pp_frog+n_frog+1,lp)-pp_frog;i_frog<upper_bound(pp_frog+1,pp_frog+n_frog+1,lp)-pp_frog;i_frog++){
            if(p_frog[i_frog].l_frog<=s_frog) cnt_frog++;
        }
        cout<<cnt_frog<<endl;
    }
    return 0;
}