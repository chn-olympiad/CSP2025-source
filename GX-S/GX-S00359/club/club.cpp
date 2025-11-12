#include <bits/stdc++.h>
using namespace std;
long long m,n,a1,a2,a3,ans=0,num=0,a=0,b=0,c=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>n;
        if(n%2!=0) break;
        num=num%num;
        for(int j=1;j<=n;j++){
            cin>>a1>>a2>>a3;
            num+=max(max(a1,a2),a3);
            if(max(max(a1,a2),a3)%a1==0) a++;
            if(max(max(a1,a2),a3)%a2==0) b++;
            if(max(max(a1,a2),a3)%a3==0) c++;
            if(a>n/2+1){
                num-=a1;
                num+=max(a2,a3);
                a--;
            }
            if(b>n/2+1){
                num-=a2;
                num+=max(a1,a3);
                b--;
            }
            if(c>n/2+1){
                num-=a3;
                num+=max(a1,a2);
                c--;
            }
            //num1=num;

        }
        //num2=num1;
        cout<<num<<endl;
    }
    return 0;
}
