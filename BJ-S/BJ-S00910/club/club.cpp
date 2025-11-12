#include <bits/stdc++.h>
using namespace std;
int arr[100005][6];
vector<int>v1,v2,v3,temp,v0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long ans=0;
        v1=v0,v2=v0,v3=v0;
        int c;
        for(int i=1;i<=n;i++){
            cin>>arr[i][1];
            cin>>arr[i][2];
            cin>>arr[i][3];
            c=max(arr[i][1],max(arr[i][2],arr[i][3]));
            ans+=c;
            if(arr[i][1]==c) v1.push_back(arr[i][1]-max(arr[i][2],arr[i][3]));
            else if(arr[i][2]==c) v2.push_back(arr[i][2]-max(arr[i][1],arr[i][3]));
            else v3.push_back(arr[i][3]-max(arr[i][2],arr[i][1]));
        }
        if(v2.size()>v1.size()&&v2.size()>v3.size()){
            temp=v1;
            v1=v2;
            v2=temp;
        }
        if(v3.size()>v1.size()&&v2.size()<v3.size()){
            temp=v1;
            v1=v3;
            v3=temp;
        }
        sort(v1.begin(),v1.end());
        if(v1.size()>n/2)for(int i=0;i<v1.size()-n/2;i++) ans-=v1[i];
        cout<<ans<<endl;
    }
    return 0;
}
