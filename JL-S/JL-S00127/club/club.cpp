#include<bits/stdc++.h>
using namespace std;
    int t,a,b,c;
    int n[10];
    bool n2,n4,A,B;
    vector<int> i[10][4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    n2=0;
    n4=0;
    A=0;
    B=0;
    for(int x=1;x<=t;x++){
        scanf("%d",&n[x]);
        if(n[x]!=2) n2=1;
        if(n[x]!=4) n4=1;
        for(int y=1;y<=n[x];y++){
            scanf("%d %d %d",&a,&b,&c);
            i[x][1].push_back(a);
            i[x][2].push_back(b);
            i[x][3].push_back(c);
            if(c!=0){
                A=1;
                B=1;
            }
            if(b!=0) A=1;
        }
    }
    if(n2==0) for(int j=1;j<=t;j++){
        int Max=0;
        for(int aa=1;aa<=3;aa++){
            for(int bb=1;bb<=3;bb++){
                if(bb!=aa) Max=max(Max,i[j][aa][0]+i[j][bb][1]);
            }
        }
        printf("%d\n",Max);
    }
    else if(n4==0) for(int j=1;j<=t;j++){
        int Max=0;
        for(int aa=1;aa<=3;aa++){
            for(int bb=1;bb<=3;bb++){
                for(int cc=1;cc<=3;cc++){
                    if(aa!=bb||aa!=cc){
                        for(int dd=1;dd<=3;dd++){
                            if(dd==aa&&dd==cc) dd=cc;
                            else if(dd==bb&&dd==cc) dd=cc;
                                else Max=max(Max,i[j][aa][0]+i[j][bb][1]+i[j][cc][2]+i[j][dd][3]);
                        }
                    }
                }
            }
        }
        printf("%d\n",Max);
    }
    else if(A==0){
        for(int x=1;x<=t;x++){
           int AA[n[x]];
           for(int y=0;y<=n[x];y++) AA[y]=i[x][1][y];
           int Max=0;
           sort(AA,AA+n[x]);
           for(int aa=n[x]-1;aa>=n[x]/2;aa--) Max+=AA[aa];
           printf("%d\n",Max);
        }
    }
    else for(int x=1;x<=t;x++){
           int AA[n[x]];
           for(int y=0;y<=n[x];y++) AA[y]=max(max(i[x][1][y],i[x][2][y]),i[x][3][y]);
           int Max=0;
           sort(AA,AA+n[x]);
           for(int aa=n[x]-1;aa>=0;aa--) Max+=AA[aa];
           printf("%d\n",Max);
        }
    return 0;
}
