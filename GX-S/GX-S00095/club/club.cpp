#include <bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int endflag=1;

int inputi(){
    int res=0,ch;
    ch=fgetc(fi);
    while(ch>='0'&&ch<='9'){
        res*=10;
        res+=ch-'0';
        ch=fgetc(fi);
    }
    return res;
}

int c[4],hn,n;
struct student{
    int id;
    int c;
    int a[4];
}stu[100005];

int dfs(int stuid){
    int res=0,tmp;
    if(stuid>n){
        return 0;
    }
    for(int i=1;i<=endflag;i++){
        if(c[i]<hn){
            c[i]++;
            tmp = dfs(stuid+1)+stu[stuid].a[i];
            if(tmp>res){
                res=tmp;
            }
            c[i]--;
        }
    }
    return res;
}

void code(){
    for(int i=0;i<=4;i++){
        c[i]=0;
    }
    n=inputi();
    hn=n/2;
    for(int i=1;i<=n;i++){
        stu[i].id=i;
        stu[i].a[1]=inputi();
        stu[i].a[2]=inputi();
        if(stu[i].a[2]!=0&&endflag==1){
            endflag=2;
        }
        stu[i].a[3]=inputi();
        if(stu[i].a[3]!=0&&endflag==2){
            endflag=3;
        }
    }
    fprintf(fo, "%d\n", dfs(1));
}

int main(){
    #if 1
    fi = fopen("club.in", "r");
    fo = fopen("club.out", "w");
    #else
    fi=stdin;
    fo=stdout;
    #endif
    int cnt=inputi();
    for(int i=1;i<=cnt;i++){
        code();
    }
}
