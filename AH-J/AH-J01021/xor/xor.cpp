#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

    bool f=false,temp,last;
    long long sum=0;
    int n,k;
    cin>>n>>k;

    if(k==0)
    {
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            if(!temp)
            {
                sum++;
            }
            else if(f && last)
            {
                sum++;
            }
            last=temp;
            f=true;
        }
    }
    else if(k)
    {
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            if(temp)
            {
                sum++;
            }
        }
    }

    cout<<sum;

    fclose(stdin);
	fclose(stdout);

    return 0;
}
