#include <bits/stdc++.h>
using namespace std;
int n,m,ansx;
vector<int> s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d",&ansx);
    s.push_back(ansx);
    for(int i=2;i<=n*m;i++){
        int x;
        scanf("%d",&x);
        s.push_back(x);
    }
    sort(s.rbegin(),s.rend());
    for(int ans=1;ans<=n*m;ans++){
        if(s[ans-1]==ansx){
            printf("%d ",((ans-1)/n)+1);
            if((((ans-1)/n)+1)%2==0)printf("%d",n-((ans-1)%n));
            else printf("%d",((ans-1)%n)+1);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

