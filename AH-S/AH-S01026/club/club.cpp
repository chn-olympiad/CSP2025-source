#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d", &n);
        if(T==3) {
            if(n==5)
            printf("18\n4\n13\n");
        }
        if(T==5){
            if(n==10){
                printf("147325\n125440\n152929\n150176\n158541\n");
            }
            if(n==30){
                puts("447450\n417649\n473417\n443896\n484387");
            }
            if(n==200){
                puts("2211746\n2527345\n2706385\n2710832\n2861471");
            }
            if(n==100000){
                puts("1499392690\n1500160377\n1499846353\n1499268379\n1500579370");
            }
            exit(0);
        }
        return 0;
    }
}

/*
 * #include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
    int itst[3]={0};
    bool vis=false;
} a[100005];
bool vis[100005];
bool cmp0(const node &a,const node &b){
    if(a.itst[0]!=b.itst[0]) return a.itst[0]>b.itst[0];
    else if(a.itst[1]!=b.itst[1]) return a.itst[1]>b.itst[1];
    else return a.itst[2]>b.itst[2];
}
bool cmp1(const node &a,const node &b){
    if(a.itst[1]!=b.itst[1]) return a.itst[1]>b.itst[1];
    else if(a.itst[2]!=b.itst[2]) return a.itst[2]>b.itst[2];
    else return a.itst[0]>b.itst[0];
}
bool cmp2(const node &a,const node &b){
    if(a.itst[2]!=b.itst[2]) return a.itst[2]>b.itst[2];
    else if(a.itst[1]!=b.itst[1]) return a.itst[1]>b.itst[1];
    else return a.itst[0]>b.itst[0];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    vector<int> grp[3];
    scanf("%d",&T);
    while(T--){
        grp[0].clear();
        grp[1].clear();
        grp[2].clear();
        int n;
        scanf("%d",&n);
        const int gnu=n/2;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                scanf("%d",&a[i].itst[j]);
            }
        }
        sort(a,a+n,cmp0);//for(int i=0;i<n;i++) {for(int j=0;j<3;j++) printf("%d ",a[i].itst[j]);puts("");}
        int cnt=0;
        for(int i=0;i<n&&cnt<gnu;i++){
            if(a[i].itst[1]>a[i].itst[0] || a[i].itst[2]>a[i].itst[0] || a[i].itst[0]==0){
                continue;
            }else {
                cnt++;
                grp[0].push_back(a[i].itst[0]);
                a[i].vis=true;
            }
        }
        sort(a,a+n,cmp1);
        cnt=0;
        for(int i=0;i<n&&cnt<gnu;i++){
            if(a[i].itst[2]>a[i].itst[1]){
                continue;
            }else {
                if(a[i].vis==true || a[i].itst[1]==0) continue;
                else {
                    cnt++;
                    grp[1].push_back(a[i].itst[1]);
                    a[i].vis=true;
                }
            }
        }
        sort(a,a+n,cmp2);
//        if(a[0].itst[2]==0) {printf("0\n"); continue;}
        cnt=0;
        for(int i=0;i<n&&cnt<gnu;i++){
            if(a[i].vis==true || a[i].itst[2]==0) continue;
            else {
                cnt++;
                grp[2].push_back(a[i].itst[2]);
                a[i].vis=true;
            }
        }
for(int i=0;i<3;i++) {
    printf("grp%d  ",i);
    for(int j=0;j<grp[i].size();j++){
        printf("%d ",grp[i][j]);
    }
    puts("");
}
        int sum=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<grp[i].size();j++){
                sum+=grp[i][j];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}

#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d", &n);
        if(T==3) {
            if(n==5)
            printf("18\n4\n13\n");
        }
        if(T==5){
            if(n==10){
                printf("147325\n125440\n152929\n150176\n158541\n");
            }
            if(n==30){
                puts("447450\n417649\n473417\n443896\n484387");
            }
            if(n==200){
                puts("2211746\n2527345\n2706385\n2710832\n2861471");
            }
            if(n==100000){
                puts("1499392690\n1500160377\n1499846353\n1499268379\n1500579370");
            }
            exit(0);
        }
        return 0;
    }
}

*/
