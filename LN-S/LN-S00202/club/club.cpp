#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        int cnt=0;
        cin>>n;
        bool flag=true;
        vector<int> a;
        a.push_back(0);
        int b[N],c[N],k;
        for(int i=1;i<=n;i++){
            cin>>k>>b[i]>>c[i];
        a.push_back(k);
            if(b[i]!=0||c[i]!=0) flag=false;
        }
        if(flag){
            sort(a.begin()+1,a.end());
            reverse(a.begin()+1,a.end());
            for(int j=1;j<=n/2;j++){
                cnt+=a[j];
            }
        }else{
        for(int j=1;j<=n;j++){
                cnt+=max(max(a[j],b[j]),c[j]);
            }
        }
        cout<<cnt<<"\n";
    }
return 0;
}
