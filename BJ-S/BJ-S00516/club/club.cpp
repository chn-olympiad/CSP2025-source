#include<bits/stdc++.h>
using namespace std;
int b[3]={},m;
struct manyidu{
    int v[3];
};
manyidu a[100010]={};
/*
bool pai(manyidu a,manyidu b){
    if(a.v[0]>a.v[0]){
        return 1;
    }
    if(a.v[0]==a.v[0]){
        if(a.v[1]>a.v[1]){
            return 1;
        }
        if(a.v[1]==a.v[1]){
            if(a.v[2]>a.v[2]){
                return 1;
            }
        }
    }
    return 0;
}
*/
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int I=0;I<t;I++){
        int n,s=0;
        cin>>n;
        m=n/2;
        for(int i=0;i<n;i++){
            cin>>a[i].v[0]>>a[i].v[1]>>a[i].v[2];
            //sort(a[i].v,a[i].v+2);
            s+=max(a[i].v[0],max(a[i].v[1],a[i].v[2]));
        }
        //sort(a,a+n-1,pai);
        /*
        for(int i=0;i<n;i++){
            s+=a[i].v[0];
        }
        */
        cout<<s<<endl;
    }
    return 0;
}

