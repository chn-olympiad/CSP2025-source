#include<bits/stdc++.h>
using namespace std;
int t,n,shuru,z1,z2,z3;
int a[100005][5];
int main(){
int l1,l2,he=0;
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);

scanf("%d",&t);
for(int as=1;as<=t;as++){

scanf("%d",&n);
    int zong[4];
    for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
        zong[1]=zong[2]=zong[3]=n/2;
            }
    for(int i=1;i<=n;i++){

            l1=1;l2=1;
        for(int j=1;j<=n;j++){
            for(int w=1;w<=3;w++){
                if(a[j][w]>a[l1][l2]&&zong[w]>0){l1=j;l2=w;}
            }
        }
        he+=a[l1][l2];
        a[l1][1]=-1;a[l1][2]=-1;a[l1][3]=-1;
        if(l2==1){zong[1]--;}
        if(l2==2){zong[2]--;}
        if(l2==3){zong[3]--;}



    }
cout<<he<<endl;
he=0;
}
return 0;

}
