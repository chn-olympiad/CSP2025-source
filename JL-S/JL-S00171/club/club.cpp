#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        int s=0;
        cin>>n;
        int l[n+1][3]={0};
        int l1[n+1][3]={0};
        int l2[3]={0};
        int l3[n+1]={0};
        for(int j=1;j<=n;j++){
            cin>>l[j][0]>>l[j][1]>>l[j][2];
            int k=max(max(l[j][0],l[j][1]),max(l[j][2],l[j][1]));
            s+=k;
            l1[j][0]=k-l[j][0];
            l1[j][1]=k-l[j][1];
            l1[j][2]=k-l[j][2];
            if(!l1[j][0]) l2[0]++;
            else if(!l1[j][1]) l2[1]++;
            else if(!l1[j][2]) l2[2]++;
            if(!l1[j][0]) l3[j]=min(min(l1[j][1],l1[j][2]),min(l1[j-1][1],l1[j-1][2]));
            else if(!l1[j][1]) l3[j]=min(min(l1[j][0],l1[j][2]),min(l1[j-1][0],l1[j-1][2]));
            else if(!l1[j][2]) l3[j]=min(min(l1[j][0],l1[j][1]),min(l1[j-1][0],l1[j-1][1]));
        }
        int k1=max(max(l2[0],l2[1]),max(l2[2],l2[1]));
        while(2*k1>l2[0]+l2[1]+l2[2]){
            int k1=max(max(l2[0],l2[1]),max(l2[2],l2[1]));
            if(!(k1-l2[0])){
                l2[0]--;
                s-=min(l3[n],l3[n-1]);
                l2[1]++;
            }
            if(!(k1-l2[1])){
                l2[1]--;
                s-=min(l3[n],l3[n-1]);
                l2[2]++;
            }
            if(!(k1-l2[2])){
                l2[2]--;
                s-=min(l3[n],l3[n-1]);
                l2[0]++;
            }
        }
        cout<<s<<endl;

    }
    return 0;
}
