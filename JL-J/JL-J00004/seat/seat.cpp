#include<bits/stdc++.h>
using namespace std;
struct stu{
    long long grade;
    bool ifR=0;
}a[103];
bool flag=0,tp=0;
bool cmp(stu i,stu j)
{
    return i.grade>j.grade;
}
int room[12][12],n,m,d=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].grade;
        if(a[i].grade==100)
        {
            flag=1;
            swap(a[i],a[1]);
        }
        if(i==1)
            a[1].ifR=1;
    }
    if(flag)
        sort(a+2,a+m*n,cmp);
    else
        sort(a+1,a+m*n,cmp);
    int j=1;
    while(1)
    {
        for(int i=1;i<=n;i++)
        {
            room[i][j]=a[d].grade;
            if(a[d].ifR==1)
            {
                cout<<j<<" "<<i;
                return 0;
            }
            d++;
        }
        j++;
        for(int i=n;i>=1;i--)
        {
            room[i][j]=a[d].grade;
            if(a[d].ifR==1)
            {
                cout<<j<<" "<<i;
                return 0;
            }
            d++;
        }
        j++;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
