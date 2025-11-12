#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define gc getchar_unlocked()
#define pc putchar_unlocked

int a[111111];
//#define DEBUG
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);

    ll n,m;cin>>n>>m;ll all=n*m;
    for(ll i=1;i<=all;i++)
    {
        cin>>a[i];
    }
    int target=a[1];//目标元素

    sort(a+1,a+all+1);//先从低到高排，一定要记得倒过来

    //二分查找

    int i=lower_bound(a+1,a+all+1,target)-a;
    if(a[i]!=target)
    {
        cout<<1<<' '<<1;//找不到答案，程序有误
        return 0;
    }
    /*
        我需要“反转”这个数组，确定target倒序的位置
        2 2
        99 100 97 98
        一共有4个数
        100 99 98 97 倒序（排在n-i+1个）
        97 98 99 100 正序（排在第三个）
        我需要在草稿纸上验证这种想法
        已经验证过了 规律是：new_i=n-i+1
    */
    int newi=all-i+1;
    //我需要确定newi在考场中的位置
    //我已经在测试程序中推出规律了

    int x=newi%m;//hang
    int y=newi/m+1;//lie
    if(x==0)
    {
        x=m;
        y--;
    }
    if(y%2==0)//如果y是偶数说明需要反转行数量
    {
        x=m-x+1;
    }
    cout<<y<<' '<<x<<endl;


    return 0;
}
