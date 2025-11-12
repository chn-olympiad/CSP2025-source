#include<bits/stdc++.h>
#define please_AC return 0
using namespace std;
int n,m,score;
bool p=true;
int a[105],sc[105],t;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    score=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        sc[i]=a[n*m-i+1];

    }
    int idx=1;
    for(int lie=1;lie<=m;lie++){

        if(p){
            for(int hang=1;hang<=n;hang++,idx++){
                if(sc[idx]==score){
                    printf("%d %d",lie,hang);
                    please_AC;
                }

            }
        }
        else{
            for(int hang=n;hang>=1;hang--,idx++){
                if(sc[idx]==score){
                    printf("%d %d",lie,hang);
                    please_AC;
                }
            }
        }
        p=!p;
    }
    please_AC;
}
