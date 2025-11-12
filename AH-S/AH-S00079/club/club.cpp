#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
};
node a[1919810];
int f[5],t,n,ans=0,M;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        memset(f,0,sizeof(f));
        cin>>n;
        priority_queue<int> q1,q2,q3;
        for(int i=0;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
    }
    for(int i=0;i<=n;i++){
        if(a[i].a>a[i].b&&a[i].a>a[i].c){
            ans+=a[i].b;
            q1.push(min(a[i].a-a[i].b,a[i].b-a[i].c));
            f[1]++;
            if(f[2]>=n/2){
             ans=q2.top();
             f[1]--;
             q1.pop();   
      }else{
          f[3]++;
     }
    }
    cout<<ans<<endl;
  }
}
}
