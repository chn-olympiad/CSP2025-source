#include <bits/stdc++.h>
using namespace std;

FILE *fi,*fo;

#define inf (1000000001)

struct road{
    int a;
    int b;
    int cost;
};

std::vector<road> r;

int inputi(){
    int res=0,ch;
    bool flag=true;
    while(flag){
        ch=fgetc(fi);
        while(ch>='0'&&ch<='9'){
            res*=10;
            res+=ch-'0';
            ch=fgetc(fi);
            flag=false;
        }
    }
    static int cnt=0;
    return res;
}

int n,m,k,mina=inf,minb=inf,minc=inf;
bool connet[10005];

bool allconnet(){
    for(int i=1;i<=n;i++){
        if(connet[i]==false){
            return false;
        }
    }
    return true;
}

int func(){
    for(int i=1;i<=n;i++){
        if(!connet[i]){
            return i;
        }
    }
    return 0;
}

bool check(){
    mina=0;
}

bool cmp(road a, road b){
    return a.cost<b.cost;
}

bool cmp1(road a, road b){
    return a.a<b.a;
}

int main(){
    #if 1
    fi = fopen("road.in", "r");
    fo = fopen("road.out", "w");
    #else
    fi=stdin;
    fo=stdout;
    #endif

    n=inputi();
    m=inputi();
    k=inputi();
    r.push_back({inf, inf, inf});
    for(int i=1;i<=m;i++){
        r.push_back({inf, inf, inf});
        int a=inputi();
        int b=inputi();
        if(a>b){
            swap(a, b);
        }
        r[i].a=a;
        r[i].b=b;
        r[i].cost=inputi();
    }
    sort(r.begin()+1, r.begin()+m+1, cmp);
    int64_t ans=0;
    for(int i=1;i<=n;i++){
        if(connet[r[i].a]==true&&connet[r[i].b]==true){
            continue;
        }
        else{
            connet[r[i].a]=true;
            connet[r[i].b]=true;
            ans+=r[i].cost;
        }
    }
    fprintf(fo, "%lld", ans);
    fclose(fo);
    ans=0;
    int64_t fp=ftell(fi);
    bool flag=false;
    for(int i=1,ac;i<=k;i++){
        ac=inputi();
        if(ac!=0){
            flag=true;
        }
        int cmin=inf,scmin=inf,fpos=1,spos=1;
        for(int j=1;j<=m;j++){
            int x=inputi();
            if(x!=0){
                flag=true;
            }
        }

    }
    if(flag){
    fseek(fi, fp, SEEK_SET);
    for(int i=1,ac;i<=k;i++){
        ac=inputi();
        if(ac!=0){
            flag=true;
        }
        int cmin=inf,scmin=inf,fpos=1,spos=1;
        for(int j=1;j<=m;j++){
            int x=inputi();
            if(x!=0){
                flag=true;
            }
            if(x<cmin){
                scmin=cmin;
                cmin=x;
                spos=fpos;
                fpos=j;
            }
            else if(x<scmin){
                scmin=x;
                spos=j;
            }
        }
        bool flag1=true;
        int allc=ac+cmin+scmin;
        for(int q=1;q<r.size();q++){
            if(r[q].a==fpos&&r[q].b==spos){
                flag1=false;
                if(allc<r[q].cost){
                    r[q].cost=allc;
                }
            }
        }
        if(flag1){
            r.push_back((road){fpos,spos,allc});
        }

    }
        sort(r.begin()+1, r.end(), cmp);
        for(int i=1;i<r.size();i++){
        }
        int64_t ans=0;
        for(int i=1;i<=n;i++){
            connet[i]=false;
        }
        for(int i=1;i<r.size();i++){
            if(connet[r[i].a]==true&&connet[r[i].b]==true){
                continue;
            }
            else{
                connet[r[i].a]=true;
                connet[r[i].b]=true;
                ans+=r[i].cost;
            }
        }
        fo = fopen("road.out", "w");
        fprintf(fo, "%lld", ans);
    }
    else{
        fo = fopen("road.out", "w");
        fprintf(fo, "0");
    }

}
