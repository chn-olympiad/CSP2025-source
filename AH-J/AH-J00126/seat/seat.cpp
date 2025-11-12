#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,m,h;
int a;
priority_queue<int> st;
int main(){
        freopen("seat.in","r",stdin);
        freopen("seat.out","w",stdout);
        cin>>n>>m;
        for(int i=1;i<=n*m;i++){
            cin>>a;
            st.push(a);
            if(i==1) h=a;
        }
        for(int j=1;j<=m;j++){
            if(j%2==1){
                for(int i=1;i<=n;i++){
                    if(st.top()==h){
                        cout<<j<<" "<<i;
                    }
                    st.pop();
                }
            }else{
                for(int i=n;i>=1;i--){
                    if(st.top()==h){
                        cout<<j<<" "<<i;
                    }
                    st.pop();
                }
            }
        }
        fclose(stdin);
        fclose(stdout);
        return 0;
}
