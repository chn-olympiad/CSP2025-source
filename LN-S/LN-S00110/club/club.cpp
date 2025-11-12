#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f,n,m,sum;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>n;
        cin>>a>>b>>c>>d>>e>>f;
        sum=0;
        sum=sum+max(a,max(b,max(c,max(d,max(e,f)))));
        if(a==sum){
            sum=sum+max(e,f);
        }
        else if(b==sum){
            sum=sum+max(d,f);
        }
        else if(c==sum){
            sum=sum+max(d,e);
        }
        else if(d==sum){
            sum=sum+max(b,c);
        }
        else if(e==sum){
            sum=sum+max(a,c);
        }
        else if(f==sum){
            sum=sum+max(a,b);
        }
        cout<<sum<<endl;
    }
    return 0;
}
