#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,xR,price;
    cin >> n >> m;
    int score[m*n];
    for(int i=0;i<m*n;i++)
    {
        cin >> score[i];
    }
    xR=score[0];
    sort(score,score+m*n,cmp);
    for(int i=0;i<m*n;i++)
    {
        if(score[i]==xR) price=i+1;
    }
    int h,l;
    l=price/n;
    if(price%n!=0||l==0) l++;
    h=price%n;
    if(h==0) h=n;
    if(l%2==0) h=n-h+1;
    cout << l << ' ' << h;
    return 0;
}
