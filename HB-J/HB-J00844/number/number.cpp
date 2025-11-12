#include<bits/stdc++.h>
using namespace std;
int N=1e6+5;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    int arr[N]={0};
    string ssr;
    cin>>ssr;
    int len=ssr.size();
    int j=1;
    for (int i=0;i<len;i++)
    {
        if (ssr[i]>='0' && ssr[i]<='9')
        {
            arr[j]=ssr[i]-'0';
            j++;
        }

    }
    sort(arr+1,arr+j);
    if (arr[j-1]==0)
        cout<<0;
    else
    {
        for (int i=j-1;i>0;i--)
        {
            cout<<arr[i];
        }
    }


    fclose(stdin);
    fclose(stdout);

    return 0;
}
