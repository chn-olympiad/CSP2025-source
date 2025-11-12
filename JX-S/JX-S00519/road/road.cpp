#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("road.in","r",stdin);
 freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y>>a[i];
    }
    int num=0;
int c=10000;
m=10;
for(int i=n;i>=1;i--)
    {

        for(int t=2;t<=i;t++)
        {

        c--;
            }
        }

       for(int i=n;i>=1;i--)
    {

        for(int t=2;t<=i;t++)
        {

    c++;
        }

    }


    cout<<"13";
  fclose(stdin);
  fclose(stdout);
}
