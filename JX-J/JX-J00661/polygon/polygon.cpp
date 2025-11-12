#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int arr[N];
long long ans=0;
long long sum;
int n;
void dfs(int i,int Max_stick,long long sum,int cishu,vector<int> vec){
    for(int j=1;j<=n;j++){
        cishu++;
        bool flag=true;
        for(int it=0;it<vec.size();it++){
            if(vec[it]==arr[j]){
                flag=false;
                break;
            }
        }
        if(Max_stick<arr[j]){
            Max_stick=arr[j];
        }
        if(sum>Max_stick*2&&flag){
                vec.push_back(arr[j]);
            dfs(j,Max_stick,sum+arr[j],cishu+1,vec);
        }
        else{
            ans++;
        }


}
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<int> vec;
    for(int i=1;i<=n;i++){
        dfs(1,-1,arr[i],1,vec);
    vec.clear();
    }
    cout<<ans;
return  0;
}
