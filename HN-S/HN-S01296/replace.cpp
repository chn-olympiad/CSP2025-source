#include <bits/stdc++.h>
using namespace std;
#define int long long
const unsigned long long HS_base=1299709;
unsigned long long A[2300005],Sum[2300005],SS[2300005],id_Sum_2[2300005],id_Sum_1[2300005],Mi_base[2300005];
unsigned long long get_1(int l,int r){
    if(l>r){
        return 0;
    }
    return id_Sum_1[r]-id_Sum_1[l-1]*Mi_base[r-l+1];
}
unsigned long long get_2(int l,int r){
    if(l>r){
        return 0;
    }
    return id_Sum_2[r]-id_Sum_2[l-1]*Mi_base[r-l+1];
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n_cha,Q_xun;
    cin>>n_cha>>Q_xun;
    for(int i=1;i<=n_cha;i++){
        string S1,S2;
        cin>>S1>>S2;
        A[i]=S1.size();
        for(int j=0;j<S1.size();j++){
            Sum[i]=Sum[i]*HS_base+S1[j];
        }
        for(int j=0;j<S2.size();j++){
            SS[i]=SS[i]*HS_base+S2[j];
        }
    }
    // for(int i=0;i<=cnt;i++){
    //     cout<<"WWW "<<i<<'\n';
    //     cout<<fail[i]<<'\n';
    //     for(int j=0;j<26;j++){
    //         cout<<(char)(j+'a')<<' '<<ch[i][j]<<'\n';;
    //     }
    //     cout<<'\n';
    // }
    for(int i=1;i<=Q_xun;i++){
        string S1,S2;
        cin>>S1>>S2;
        if(S1.size()!=S2.size()){
            cout<<0<<'\n';
            continue;
        }
        int n=S1.size();
        S1=" "+S1;
        S2=" "+S2;
        Mi_base[0]=1;
        for(int j=1;j<=n;j++){
            id_Sum_2[j]=id_Sum_2[j-1]*HS_base+S2[j];
            id_Sum_1[j]=id_Sum_1[j-1]*HS_base+S1[j];
            Mi_base[j]=Mi_base[j-1]*HS_base;
        }
        int Id_zheng=0,Id_ni=n+1;
        for(int j=1;j<=n;j++){
            if(S1[j]==S2[j]){
                Id_zheng++;
            }else{
                break;
            }
        }
        for(int j=n;j>=1;j--){
            if(S1[j]==S2[j]){
                Id_ni--;
            }else{
                break;
            }
        }
        int daan=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n_cha;k++){
                if(A[k]>j){
                    continue;
                }
                if(j-A[k]<=Id_zheng && j+1>=Id_ni){
                    if(get_1(j-A[k]+1,j)==Sum[k] && get_2(j-A[k]+1,j)==SS[k]){
                        daan++;
                    }
                }
            }
        }
        cout<<daan<<'\n';
    }
    return 0;
}