#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int q=0;
    int cm;
    cin>>q;
    int d[101];
    for(int i=0;i<=q;i++){
        cin>>d[i];
    }
    for(int i=0;i<=q;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=j;k++){
                    int as;
                    int gh;
                    as = d[i]+d[j]+d[k];
                    if(d[i] > d[j])
                         if(d[i] > d[k])
                            gh = d[i];
                        else
                            gh = d[k];
                    else if(d[j] > d[k])
                        gh = d[i];
                    else
                        gh = d[k];


                if(as>gh*2)
                    cm++;
                int q1,q2,q3;
                if(d[i]< d[j])
                    q1 = d[j];
                else
                    q1 = d[i];

                if(d[j]< d[k])
                    q2 = d[k];
                else
                    q2 = d[j];

                if(d[k]< d[i])
                    q3 = d[i];
                else
                    q3 = d[k];
                int y1,y2,y3;
                y1=d[i]+d[j];
                y2=d[j]+d[k];
                y3=d[k]+d[i];
                if(y1>q1*2)
                    cm++;
                if(y2>q2*2)
                    cm++;
                if(y3>q3*2)
                    cm++;





    cout<<cm;
    return 0;
            }
        }
    }
}
