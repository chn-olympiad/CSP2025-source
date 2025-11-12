#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int t,n;
int main()
{
    freopen("club.in""r",stdin);
    freopen("club.out""w",stdout);

    cin>>t;
    while(t=!0){
        int a=0,b=0,c=0,a1=0,b1=0,c1=0;
        int sum=0;
        cin>>n;
        for(int i=1;i<n;i++){
            cin>>a>>b>>c;
            if(a==max(a,b,c)){a1++;};
            if(b==max(a,b,c)){b1++;};
            if(c==max(a,b,c)){c1++;};
            if(a1<=(n/2)&&b1<=(n/2)&&c1<=(n/2)){sum+=max(a,b,c);}
        }
        cout<<sum<<endl;
        t--;
    }
    fclose("club.in");
    fclose("club.out");
    return 0;
}
