#include <bits/stdc++.h>
#define il inline
#define rg register
using namespace std;
using ll = long long;
int n,m,score;
int a[1050];
bool cmp(int a,int b){
    return a<b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);

    for(int i = 1;i<=n*m;i++) scanf("%d",a+i);
    score = a[1];
    //cerr << n << m;
    sort(a+1,a+1+n*m,greater<int>());
    int num = 0;
    int lft = 1;
    int rgt = n*m;
    while(lft<=rgt){
        int mid = (lft+rgt)>>1;
        if(a[mid] == score){
            num = mid;
            break;
        } else if(a[mid]>score) lft = mid+1;
        else rgt = mid-1;
    }
    int r = (num-1)/(2*n)*2;
    int c = num-r*n;
    //cerr << c;
    if(c>n) c=n-(c-n)+1,r++;
    printf("%d %d",r+1,c);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
