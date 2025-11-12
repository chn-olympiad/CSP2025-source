#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;int cnt=0,cnt2=0;int tmp=-1;bool flag=false;
    int a=0,b=0;
    vector<int>q;bool flag1=true;

    if(n>1000){
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x==0){
                a++;flag=false;
            }
            else{
                if(flag){
                    flag=false;
                    cnt2++;
                }
                else flag=true;
                b++;
            }
        }
        if(k==1)cout<<b;
        else{
            cout<<a+cnt2;
        }
        return 0;
    }

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==k){
            q.clear();
            cnt++;
        }
        else{
            for(int y:q){
                y^=x;
                if(y==k){
                    cnt++;
                    q.clear();
                    break;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
//50min  only30pts
