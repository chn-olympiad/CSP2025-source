#include<bits/stdc++.h>
using namespace std;
int t,n,t1,t2,sum,pu,sum1;
vector<int> pc;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        sum=0;
        sum1=0;
        cin>>n;
        int flag=1;
        for(int j=0;j<n;j++){
            cin>>pu>>t1>>t2;
            int s[3]={pu,t1,t2};
            sum1+=s[max_element(s,s+3)-s];
            if(t1!=0 or t2!=0){
                flag=0;
            }
            pc.push_back(pu);
        }
        if(flag==1){
            for(int j=0;j<n/2;j++){
                sum+=*max_element(pc.begin(),pc.end());
                pc.erase(max_element(pc.begin(),pc.end()));

            }
            cout<<sum;
        }else{
           cout<<sum1;
        }
    }
    return 0;
}
