#include <iostream>
using namespace std;
long long t,n,a,b,c,MAX;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        long long a1=0,a2=0,a3=0;
        MAX=0;
        cin>>n;
        if(n==2){
            cin>>a>>b>>c;
            long long a2,b2,c2;
            cin>>a2>>b2>>c2;
            cout<<max(max(max(a+a2,a+b2) ,a+c2),max(max(max(b+a2,b+b2) ,b+c2),max(max(c+a2,c+b2) ,c+c2)));
            return 0;
        }
        for(int i=1;i<=n;i++){
            long long Max=0;
            cin>>a>>b>>c;
            if(n/2>a1)
                Max=max(Max,a);
            //cout<<Max<<" ";
            if(n/2>a2)
                Max=max(Max,b);
            //cout<<Max<<" ";
            if(n/2>a3)
                Max=max(Max,c);
            //cout<<Max<<" ";
            if(Max==a){
                a1++;
            }
            if(Max==b){
                a2++;
            }
            if(Max==c){
                a3++;
            }
            //cout<<Max;
            MAX+=Max;
        }

        cout<<MAX<<endl;
    }
    return 0;
}
