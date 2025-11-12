#include <bits/stdc++.h>
using namespace std;

int max_per(int x){
    int ret=1;
    for(int i=1;i<=x;i++){
        ret*=i;
    }
    return ret;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int sticks[n];
    for(int i=0;i<n;i++){
        cin>>sticks[i];
    }
    sort(sticks,sticks+n);
    int ans=0;
    for(int i=3;i<=n;i++){
        int per=max_per(i);
        int this_ans=0;
        while(next_permutation(sticks,sticks+n))
        {
            int sum=0,max=0;
            for(int x=0;x<i;x++){
                sum+=sticks[x];
                if(sticks[x]>max){
                    max=sticks[x];
                }
            }
            if(sum>max*2){
                this_ans++;
                for(int x=0;x<i;x++){
                    cout<<sticks[x]<<" ";
                }
                cout<<endl;
            }
        }
        this_ans/=per;
        ans+=this_ans;
    }
    cout<<ans-1;
    return 0;
}