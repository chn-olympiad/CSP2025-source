#include <bits/stdc++.h>
using namespace std;
int n,k,l,cnt;
int num[5*100001],num1[5*100001];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        num[i]=num[i]^k;
    }
    for(int i=1;i<=n;i++)
    {
        num1[i]=num[i]^num1[i-1];
        if(i==l+1 && num[i]==0)
        {
            l=i;
            num1[l]=0;
            cnt++;
        }
        else if(num1[i]==0  && num[i]!=num[i-1] || num[i]==0)
        {
            l=i;
            num1[l]=0;
            cnt++;
        }
        else
        {
            for(int j=l+1;j<i;j++)
            {
                if(num1[j]==num1[i]&& num[j]!=num[i])
                {
                    l=i;
                    num1[l]=0;
                    cnt++;
                    break;
                }
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
