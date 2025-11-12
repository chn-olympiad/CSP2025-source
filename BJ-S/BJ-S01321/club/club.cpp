#include<bits/stdc++.h>
using namespace std;
int a1[100009],a2[100009],a3[100009],c1[100009],c2[100009],c3[100009],b1[100009],b2[100009],b3[100009],cl[100009];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
     int n,j1=0,j2=0,j3=0,z1=0,z2=0,z3=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a1[i]>>a2[i]>>a3[i];
        c1[i]=a1[i];
        c2[i]=a2[i];
        c3[i]=a3[i];
        b1[i]=a1[i];
        b2[i]=a2[i];
        b3[i]=a3[i];
        if(a1[i]>a2[i]){
            if(a1[i]>a3[i]){
                cl[i]=1;
                j1++;
                z1+=a1[i];
            }else{
                cl[i]=3;
                j3++;
                z3+=a3[i];
            }
        }else{
            if(a2[i]>a3[i]){
                cl[i]=2;
                j2++;
                z2+=a2[i];
            }else{
                cl[i]=3;
                j3++;
                z3+=a3[i];
            }
        }
    }
    if(j1>n/2){
        for(int i=1;i<=n;i++){
            if(cl[i]==1){
                a2[i]=a1[i]-a2[i];
                a3[i]=a1[i]-a3[i];
            }else{
                a2[i]=1009;
                a3[i]=1009;
            }
        }
        sort(a2+1,a2+n+1);
        sort(a3+1,a3+n+1);
        int x=1,y=1;
        while(j1>n/2){
            if(a2[y]>a3[x] and j3+1<=n/2){
                z1-=a3[x];
                j3++;
                x++;
            }else{
                z1-=a2[y];
                j2++;
                y++;
            }
        }
    }
    if(j2>n/2){
        for(int i=1;i<=n;i++){
            if(cl[i]==2){
                b1[i]=b2[i]-b1[i];
                b3[i]=b2[i]-b3[i];
            }else{
                b1[i]=1009;
                b3[i]=1009;
            }
        }
        sort(b1+1,b1+n+1);
        sort(b3+1,b3+n+1);
        int x=1,y=1;
        while(j1>n/2){
            if(b1[y]>b3[x] and j3+1<=n/2){
                z2-=b3[x];
                j3++;
                x++;
            }else{
                z2-=b1[y];
                j1++;
                y++;
            }
        }
    }
    if(j3>n/2){
        for(int i=1;i<=n;i++){
            if(cl[i]==3){
                b1[i]=b3[i]-b1[i];
                b2[i]=b3[i]-b2[i];
            }else{
                b1[i]=1009;
                b2[i]=1009;
            }
        }
        sort(b1+1,b1+n+1);
        sort(b2+1,b2+n+1);
        int x=1,y=1;
        while(j3>n/2){
            if(b1[y]>b2[x] and j2+1<=n/2){
                z3-=b2[x];
                j2++;
                x++;
            }else{
                z3-=b1[y];
                j1++;
                y++;
            }
        }
    }
    cout<<z1+z2+z3<<endl;       
    }

    return 0;
}
