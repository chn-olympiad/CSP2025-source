#include <bits/stdc++.h>
using namespace std;
int fin(int x,int y,int z){
    if(x>y){
        swap(x,y);
    }if(y>z){
        swap(y,z);
    }return y;
}
int ind(int x,int y,int z){
    return (fin(x,y,z)==x?0:(fin(x,y,z)==y?1:2));
}
int t(){
    int p,x,y,z,n,sum=0,m;
    cin>>p;vector<int> q[3];
    for(int i=0;i<p;i++){
        cin>>x>>y>>z;
        n=fin(x,y,z);
        m=max(x,max(y,z));
        sum+=m;
        q[ind(x,y,z)].push_back(m-n);

    }
    for(int i=0;i<3;i++){
        if(q[i].size()-1>p/2){
            sort(q[i].begin(),q[i].end());
            for(int j=0;j+p/2<=q[i].size();j++){
                sum-=q[i][j];
            }break;
        }
    }cout<<sum;
    return 0;
}
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
    int wan;
    cin>>wan;
    for(int i=0;i<wan;i++){
        t();
    }
    return 0;
}
