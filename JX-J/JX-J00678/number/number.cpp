#include<bits/stdc++.h>

using namespace std;
int num[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n;
    string a;
    cin>>a;
    n=a.size();
    for(int i=0;i<12;i++)
    {
        num[i]=0;
    }

    for(int i=0;i<n;i++){
        if(a[i]>='0' and a[i]<='9'){
            num[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        while(num[i]>0){
            cout<<i;
            num[i]--;
        }
    }
    return 0;
}
