#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","r",stdout);
    int n,m,r;
    set<int> st;
    cin>>n>>m;
    int a=n*m;
    int cnt=0;
    for(int i=1;i<=a;i++){
        int b;
        cin>>b;
        st.insert(b);
        if(i==1) r=b;
    }
    for(int i=m;i>=1;i--){
        if(i%2==1){
            for(int j=n;j>=1;j--){
                cnt++;
                int cnt2=0;
                for(int num:st){
                    cnt2++;
                    if(cnt2==cnt){
                        if(num==r) cout<<i<<" "<<j;
                    }
                }
            }
        }
        if(i%2==0){
            for(int j=1;j<=n;j++){
                cnt++;
                int cnt2=0;
                for(int num:st){
                    cnt2++;
                    if(cnt2==cnt){
                        if(num==r) cout<<i<<" "<<j;
                    }
                }
            }
        }
    }
}
