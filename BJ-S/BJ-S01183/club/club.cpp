#include<bits/stdc++.h>
int n,t;
struct pe{
    int a,b,c;
}x1[int(1e5+10)],x2[int(1e5+10)],x3[int(1e5+10)];
void f(){
    int sum;
    int l1=1,l2=1,l3=1,s1=0,s2=0,s3=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        pe a;
        scanf("%d %d %d",&a.a,&a.b,&a.c);
        int mx=std::max(a.a,std::max(a.b,a.c));
        if(mx==a.a)x1[l1++]=a,s1+=a.a;
        else if(mx==a.b)x2[l2++]=a,s2+=a.b;
        else x3[l3++]=a,s3+=a.c;
    }
    if(l1>n/2){
        
    }
    else{
        for(int i=1;i<=l1;i++)sum+=x1[i].a;
        for(int i=1;i<=l1;i++)sum+=x2[i].b;
        for(int i=1;i<=l1;i++)sum+=x3[i].c;
    }
    printf("%d\n",sum);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)f();
}
