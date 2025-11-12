#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
}a[114514];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int h;
    scanf("%d",&h);
    while(h--)
    {
        int num=0;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            int t[3];
            t[0]=a[i].x,t[1]=a[i].y,t[2]=a[i].z;
            sort(t,t+3);
            if(i<=n/2) num+=t[2];
            else num+=t[1];
        }
        cout<<num<<endl;
    }
    return 0;
}
