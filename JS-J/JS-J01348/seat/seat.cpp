#include<bits/stdc++.h>
using namespace std;

int ef(vector < int > a , int cz){

    return 0;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n , m;
    scanf("%d%d",&n,&m);
    int zr = n * m,rf;
    vector < int > a(zr+1);
    for(int i = 1;i <= zr;i ++){
        scanf("%d",&a[i]);
        if(i == 1)rf = a[i];
    }
    sort(a.begin(),a.end());
    int po = 0;

    int len = a.size();
    int l = 0,r = a.size();
    while(l < r){
        int mid = (l + r)/2;
        if(a[mid] == rf){
            po = mid;
            break;
        }
        else if(a[mid] > rf)r = mid+1;
        else l = mid;
    }

    int dis = a.size() - po;
    //cout << dis << " ";
    int lie = (dis-1) / n+1;
    int hang = (dis-1) % n + 1;
    printf("%d ",lie);
    if(lie % 2 == 1)printf("%d",hang);
    else printf("%d",n - hang + 1);
    return 0;
}
