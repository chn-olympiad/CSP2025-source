#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int a[105];
for(int i=0;i<n*m;i++){
    cin>>a[i];
}
int r=a[0];
int ok[105];
for(int j=1;j<=n*m;j++){
int ans=-1;
int x=-1;
for(int i=1;i<n*m;i++){
    if(a[i]>ans){
        ans=a[i];
        x=i;
    }
}
if(ans==-1)
    break;
ok[j]=ans;
a[x]=-1;
}
int we;
for(int i=1;i<=n*m;i++){
    if(r>ok[i+1] && r<ok[i]){
        we=i+1;
    }
}
cout<<(we+m-1)/n<<" ";
if(we-we/(n*2)*(n*2)<=n && we-we/(n*2)*(n*2)>0)
    cout<<we-we/(n*2)*(n*2);

else
    cout<<2*n-(we-we/(n*2)*(n*2))+1;
return 0;
}
