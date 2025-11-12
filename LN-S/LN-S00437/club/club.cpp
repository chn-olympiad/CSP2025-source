#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct stu{
    int m1;
    int m2;
    int m3;
    bool eq = false;
    bool three_body = false;
};

int t,n,limit,p1,p2,p3;
stu a[100010],to_m1[100010],to_m2[100010],to_m3[100010];
bool flag = true;

bool cmp(stu p1,stu p2){
    return max(max(p1.m1,p1.m2),p1.m3)>max(max(p2.m1,p2.m2),p2.m3);
}


int calc(int p1,int p2,int p3){
    int ans=0;
    for(int i=0;i<p1;i++){
        ans+=to_m1[i].m1;
    }
    for(int i=0;i<p2;i++){
        ans+=to_m2[i].m2;
    }
    for(int i=0;i<p3;i++){
        ans+=to_m3[i].m3;
    }
    return ans;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        n=0;
        for(int j=0;j<n;j++){
            a[j].m1=0;
            a[j].m2=0;
            a[j].m3=0;
            a[j].eq = false;
            a[j].three_body = false;
        }
        scanf("%d",&n);
        limit = n/2,p1=0,p2=0,p3=0;
        for(int j=0;j<n;j++){
            scanf("%d",&a[j].m1);
            scanf("%d",&a[j].m2);
            scanf("%d",&a[j].m3);
            if(a[j].m3!=0)flag = false;
            if(a[j].m1==a[j].m2&&a[j].m1==a[j].m3){
                a[j].three_body = true;
            }
            else if(a[j].m1==a[j].m2||a[j].m1==a[j].m3||a[j].m3==a[j].m2){
                a[j].eq = true;
            }
        }
        sort(a,a+n,cmp);
//from here can be problems
        if(flag){
            long long ans =0;
            int x1=0,x2=0;bool flag1=false,flag2=false;
            sort(a,a+n,cmp);
            for(int j=0;j<n;j++){
                if(flag1){
                    ans+=a[j].m2;
                }
                else if(flag2){
                    ans+=a[j].m1;
                }
                else{
                    ans+=max(a[j].m1,a[j].m2);
                    if(max(a[j].m1,a[j].m2)==a[j].m1){
                        x1++;
                        if(x1==n/2)flag1=true;
                    }
                    else{
                        x2++;
                        if(x2==n/2)flag2=true;
                    }
                }
            }
            printf("%lld\n",ans);
        }
        else{
        for(int j=0;j<n&&(!a[j].eq&&!a[j].three_body);j++){
            int tmxp = max(max(a[j].m1,a[j].m2),a[j].m3);
//            int tmip = min(min(a[j].m1,a[j].m2),a[j].m3);
            if(tmxp==a[j].m1){
                to_m1[p1]=a[j];
                p1++;
                continue;
            }
            else if(tmxp==a[j].m2){
                to_m2[p2]=a[j];
                p2++;
                continue;
            }
            else{
                to_m3[p3]=a[j];
                p3++;
                continue;
            }
        }

//wrong answer solved
        for(int j=0;j<n&&a[j].eq;j++){
            int tmip = min(min(a[j].m1,a[j].m2),a[j].m3);
            if((a[j].m1==tmip&&a[j].m2==tmip)||(a[j].m1==tmip&&a[j].m3==tmip)||(a[j].m3==tmip&&a[j].m2==tmip)){
                int tmxp = max(max(a[j].m1,a[j].m2),a[j].m3);
                if(tmxp==a[j].m1){
                    to_m1[p1]=a[j];
                    p1++;
                    continue;
                }
                else if(tmxp==a[j].m2){
                    to_m2[p2]=a[j];
                    p2++;
                    continue;
                }
                else{
                    to_m3[p3]=a[j];
                    p3++;
                    continue;
                }
            }
            else{
                    if(tmip==a[j].m1){
                    if(p2<p3){
                        to_m2[p2]=a[j];
                        p2++;
                    }
                    else{
                        to_m3[p3]=a[j];
                        p3++;
                    }
                    continue;
                }
                else if(tmip==a[j].m2){
                    if(p1<p3){
                        to_m1[p1]=a[j];
                        p1++;
                    }
                    else{
                        to_m3[p3]=a[j];
                        p3++;
                    }
                }
                else {
                    if(p1<p2){
                        to_m1[p1]=a[j];
                        p1++;
                    }
                    else{
                        to_m2[p2]=a[j];
                        p2++;
                    }
                }
            }
        }
//wrong answer solved
        for(int j=0;j<n&&a[j].three_body;j++){
            int pmin = min(min(p1,p2),p3);
            if(pmin==p1){
                to_m1[p1]=a[j];
                p1++;
            }
            else if(pmin==p2){
                to_m2[p2]=a[j];
                p2++;
            }
            else{
                to_m3[p3]=a[j];
                p3++;
            }
        }
// problem is solved

         sort(to_m1,to_m1+p1,cmp);
         sort(to_m2,to_m2+p2,cmp);
         sort(to_m3,to_m3+p3,cmp);

        if(p1<=limit&&p2<=limit&&p3<=limit){
            int ans = calc(p1,p2,p3);
            printf("%d\n",ans);
        }
//wrong answer isn`t below
        else{
//            for(int j=0;j<p2;j++){
//                printf("%d ",to_m2[j].m2);
//            }
//            printf("\n");
            if(p1>limit){
                for(int j=p1-1;j>=0&&p1>limit;j--){
                    if(to_m1[j].m2>to_m1[j].m3){
                        to_m2[p2]=to_m1[j];
                        p2++;p1--;
                    }
                    else{
                        to_m3[p3]=to_m1[j];
                        p3++;p1--;
                    }
                }
            }
            else if(p2>limit){
                for(int j=p2-1;j>=0&&p2>limit;j--){
                    if(to_m2[j].m1>to_m2[j].m3){
                        to_m1[p1]=to_m2[j];
                        p1++;p2--;
                    }
                    else{
                        to_m3[p3]=to_m2[j];
                        p3++;p2--;
                    }
                }
            }
            else{
                for(int j=p3-1;j>=0&&p3>limit;j--){
                    if(to_m3[j].m1>to_m3[j].m2){
                        to_m1[p1]=to_m3[j];
                        p1++;p3--;
                    }
                    else{
                        to_m2[p2]=to_m3[j];
                        p2++;p3--;
                    }
                }
            }
        int ans = calc(p1,p2,p3);
        printf("%d\n",ans);
        }
//            printf("%d",calc(p1,p2,p3));
        }
    }

    return 0;
}
