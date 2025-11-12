#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x,y,z;
};
Node a[100005];
Node a1[100005];
Node a2[100005];
Node a3[100005];
int in1,in2,in3;
bool cmp1(Node m,Node n){
    if(min(abs(m.x-m.y),abs(m.x-m.z))!=min(abs(n.x-n.y),abs(n.x-n.z))){
        return min(abs(m.x-m.y),abs(m.x-m.z))>min(abs(n.x-n.y),abs(n.x-n.z));
    }
    return m.x>n.x;
}
bool cmp2(Node m,Node n){
    if(min(abs(m.y-m.x),abs(m.y-m.z))!=min(abs(n.y-n.x),abs(n.y-n.z))){
        return min(abs(m.y-m.x),abs(m.y-m.z))>min(abs(n.y-n.x),abs(n.y-n.z));
    }
    return m.y>n.y;
}
bool cmp3(Node m,Node n){
    if(min(abs(m.z-m.x),abs(m.z-m.y))!=min(abs(n.z-n.x),abs(n.z-n.y))){
        return min(abs(m.z-m.x),abs(m.z-m.y))>min(abs(n.z-n.x),abs(n.z-n.y));
    }
    return m.z>n.z;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            scanf("%d%d%d",&a[j].x,&a[j].y,&a[j].z);
        }
        int num1=0,num2=0,num3=0;
        for(int j=1;j<=n;j++){
            if(max(max(a[j].x,a[j].y),a[j].z)==a[j].x){
                num1++;
                a1[++in1]=a[j];
            }
            if(max(max(a[j].x,a[j].y),a[j].z)==a[j].y){
                num2++;
                a2[++in2]=a[j];
            }
            if(max(max(a[j].x,a[j].y),a[j].z)==a[j].z){
                num3++;
                a3[++in3]=a[j];
            }
        }
        sort(a1+1,a1+1+num1,cmp1);
        sort(a2+1,a2+1+num2,cmp2);
        sort(a3+1,a3+1+num3,cmp3);
        while(num1>n/2){
            if(a1[num1].y>a1[num1].z){
                a2[++num2]=a1[num1];
                num1--;
            }else{
                a3[++num3]=a1[num1];
                num1--;
            }
        }
        while(num2>n/2){
            if(a2[num2].x>a2[num2].z){
                a1[++num1]=a2[num2];
                num2--;
            }else{
                a3[++num3]=a2[num2];
                num2--;
            }
        }
        while(num3>n/2){
            if(a3[num3].x>a3[num3].y){
                a1[++num1]=a3[num3];
                num3--;
            }else{
                a2[++num2]=a3[num3];
                num3--;
            }
        }
        int ans=0;
        for(int i=1;i<=num1;i++){
            ans+=a1[i].x;
        }
        for(int i=1;i<=num2;i++){
            ans+=a2[i].y;
        }
        for(int i=1;i<=num3;i++){
            ans+=a3[i].z;
        }
        printf("%d\n",ans);
        in1=0;
        in2=0;
        in3=0;
    }
    return 0;
}
