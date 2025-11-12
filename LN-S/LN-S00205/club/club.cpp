#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int q=0;q<t;q++)
    {
        int n;
        cin>>n;
        int chuangkou1[n];
        int chuangkou2[n];
        int chuangkou3[n];
        for(int w=0;w<n;w++)
        {
            cin>>chuangkou1[w]>>chuangkou2[w]>>chuangkou3[w];

        }
        sort(chuangkou1,chuangkou1+n);
        int geshu=n/2;
        int zongshu=0;
        for(int q=n-1;q>=n-n/2-1;q--)
        {
            zongshu+=chuangkou1[q];
        }
        cout<<zongshu<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
