#include<bits/stdc++.h>
using namespace std;
int n,m,Rscore,cnt_moreR=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int num=n*m,k;
    for(int i=1;i<=num;i++)
    {
        cin>>k;
        if(i==1)
            Rscore=k;
        else if(k>Rscore)
            cnt_moreR++;
    }
    if(!cnt_moreR)
    {
        cout<<"1 1";
        return 0;
    }
    int hang=cnt_moreR/n+1;
    int yu=cnt_moreR%n;
    cout<<hang<<' ';
    if(hang%2==1) cout<<yu+1;
    else cout<<n-yu;
    return 0;
}
