#include<bits/stdc++.h>
using namespace std;
int c[4][100001],cl[100001],c1[4],t,n;
int change(int num){
    while(c1[num]>n/2)
    {
        int del1=2147483647,del2=2147483647,del=0;
        for(int i=1;i<=n;i++){
            if(cl[i]!=num)
                continue;
            del2=min(del1,c[num][i]-max(c[1][i],max(c[2][i],c[3][i])));
            if(del1!=del2)
            {
                del1=del2;
                del=i;
            }
        }
        if(num!=3)
            cl[del]++;
        else
            cl[del]=1;
    }
    return 0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int z=1;z<=t;z++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>c[1][i]>>c[2][i]>>c[3][i];
            if(c[1][i]>=c[2][i] && c[1][i]>=c[3][i]){
                cl[i]=1;
                c1[1]++;
            }
            else if(c[2][i]>=c[3][i]){
                cl[i]=2;
                c1[2]++;
            }
            else{
                cl[i]=3;
                c1[3]++;
            }
        }
        if(c1[1]>n/2)
            change(1);
        if(c1[2]>n/2)
            change(2);
        if(c1[3]>n/2)
            change(3);
        int ans=0;
        for(int i=1;i<=n;i++)
            ans+=c[cl[i]][i];
        cout<<ans;
        c1[1]=0;
        c1[2]=0;
        c1[3]=0;
    }
    return 0;
}

