#include<iostream>
#include<set>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sc,rsc;
    cin>>n>>m;
    set<int> st;
    cin>>rsc;
    st.insert(rsc);
    for(int i=1;i<m*n;i++){
        cin>>sc;
        st.insert(sc);
    }
    auto it=st.rbegin();
    for(int i=1;i<=m;i++){
        if(i%2==1){
          for(int j=1;j<=n;j++){
            if(*it==rsc){
                cout<<i<<' '<<j;
                return 0;
            }
            it++;
          }
        }
        else{
          for(int k=n;k>=1;k--){
            if(*it==rsc){
                cout<<i<<' '<<k;
                return 0;
            }
            it++;
          }
        }
    }
    return 0;
}
