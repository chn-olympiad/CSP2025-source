#include<bits/stdc++.h>
using namespace std;
int a1[100005],a2[100005],a3[100005],n;
int bfs(int aa1,int aa2,int aa3,int sum,int i){
    if(i>=n){
        return sum;
    }
    int a=0,b=0,c=0;
    if(aa1<n/2) a=bfs(aa1+1,aa2,aa3,sum+a1[i],i+1);
    if(aa2<n/2) b=bfs(aa1,aa2+1,aa3,sum+a2[i],i+1);
    if(aa3<n/2) c=bfs(aa1,aa2,aa3+1,sum+a3[i],i+1);
    return max(max(a,b),c);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a1[i]>>a2[i]>>a3[i];
        }
        cout<<bfs(0,0,0,0,0)<<endl;
    }
    return 0;
}
