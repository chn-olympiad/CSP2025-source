#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,score[110],rseat,r,c;
    cin >> n >> m;
    bool first=true;
    for(int i=0;i<n*m;i++){
        cin >> score[i];
        if(score[0]>score[i]&&first){
            rseat=i;
            first=false;
        }
    }
    if(rseat%m==0) c=rseat/m;
    else c=(rseat/m)+1;
    if(c%2!=0) r=rseat-((c-1)*m);
    else r=m-(rseat-m)+1;
    cout << c <<' '<<r;
    return 0;
}
