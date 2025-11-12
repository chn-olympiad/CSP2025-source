#include <iostream>
using namespace std;
int n;
int bsf=3;
int abi[10001]{false};
int a[10001];
int dg(int g);
int temp[10001];
int over=0;
int search(int bsf,int f);
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin >>a[i];
    }
    int jsq=0;
    for(int i=bsf;i<=n;i++)
    {
        search(i,1);
    }
    cout <<over;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
int jsq=0;
int search(int bsf,int f)
{
    for(int i=0;i<n;i++)
    {
        if(jsq<bsf)
        {
            if(abi[i]==false)
            {
                temp[i]=a[i];
                abi[i]=true;
            }
            else i++;
            jsq++;
        }
        if(jsq+1==bsf)
        {
            int sum=0;
            int temp2;
            for(int k=0;k<bsf;k++)
            {
                for(int h=0;h<bsf;h++)
                {
                    if(temp[h]<temp[h+1])
                    {
                        temp2=temp[h];
                        temp[h]=temp[h+1];
                        temp[h+1]=temp2;
                    }
                }
            }
            for(int i=0;i<bsf;i++)
            {
                sum+=temp[i];
            }
            if(temp[1]*2<sum)
            {
                over+1;
            }
        }
    }
}