#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define mod 998244353;
using namespace std;
int stick_num;
long long ans;
vector <int> vec={0};
vector <long long> sum={0};
deque <long long> deq={0};
void READ()
{
    cin>>stick_num;
    for (int i=1;i<=stick_num+1;i++)
        vec.push_back(0),cin>>vec[i];
    sort (vec.begin(),vec.end());
    for (int i=1;i<=stick_num+1;i++)
        sum.push_back(0);
    for (int i=stick_num;i;--i)
        sum[i]=sum[i+1]+vec[i];
}
void check(int i,int j)
{
    long long max_add=sum[i]-sum[j];
    while (!deq.empty()&&deq.front()+max_add<=vec[i])
        deq.pop_front();
}
void copy(long long add)
{
    long long len=deq.size();
    for (int i=1;i<len;i++)
        deq.push_back(deq[i]+add);
    sort (deq.begin(),deq.end());
}
void caculate()
{
    for (int i=3;i<=stick_num;++i)
        for (int j=1;j<i;j++)
            check(i,j),copy(vec[j]);
    ans=(ans+deq.size())%mod;
}
int main()
{
    READ();
    caculate();
    cout<<ans;
    return 0;
}
