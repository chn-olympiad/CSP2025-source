#include <bits/stdc++.h>
using namespace std;

int t,n,maxnum=0;
bool o=true,p=true;

struct student{
    int a1,a2,a3;
    int name;
    int cha;
};
student s[100001];

bool cmp(student a,student b){
    return a.a1>b.a1;
}
bool cmp1(student a,student b){
    return a.cha>b.cha;
}

int dfs(int k,int a,int b,int c,int num){
    if(k==n){
        maxnum=max(maxnum,num);
    }
    if(a<n/2){
        dfs(k+1,a+1,b,c,num+s[k].a1);
    }
    if(b<n/2){
        dfs(k+1,a,b+1,c,num+s[k].a2);
    }
    if(c<n/2){
        dfs(k+1,a,b,c+1,num+s[k].a3);
    }
    return 0;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        maxnum=0;
        for(int j=0;j<n;j++){
            scanf("%d %d %d",&s[j].a1,&s[j].a2,&s[j].a3);
            if(s[j].a2!=0 or s[j].a3!=0){
                o=false;
            }
            if(s[j].a3!=0){
                p=false;
            }
            s[j].name=j;
        }

        if(o==true){
            sort(s,s+n,cmp);
            for(int j=0;j<n/2;j++){
                maxnum+=s[j].a1;
            }
        }else if(p==true){
            for(int j=0;j<n;j++){
                s[j].cha=abs(s[j].a1-s[j].a2);
            }
            sort(s,s+n,cmp1);
            int a=0,b=0;
            for(int j=0;j<n;j++){
                if(s[j].a1>s[j].a2){
                    if(a<n/2){
                        a++;
                        maxnum+=s[j].a1;
                    }else{
                        maxnum+=s[j].a2;
                        b++;
                    }
                }else if(s[j].a1<s[j].a2){
                    if(b<n/2){
                        maxnum+=s[j].a2;
                        b++;
                    }else{
                        a++;
                        maxnum+=s[j].a1;
                    }
                }
            }
        }else{
            sort(s,s+n,cmp);
            dfs(0,0,0,0,0);
        }
        printf("%d\n",maxnum);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
