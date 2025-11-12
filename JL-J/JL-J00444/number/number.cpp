#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
cin>>n;
for(int i=0;i<n.size();i++)
{
    if(n[i]>n[i+1])
    {
        swap(n[i],n[i+1]);
    }
}
cout<<n;

}
