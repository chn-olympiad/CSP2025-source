#include <bits/stdc++.h>
using namespace std;
int a[100050][5],book[100050],c[100050];
int nummax[100050];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i; i<=t; i++)
    {
        int n;
        cin>>n;
        int num1=0,num2=0,num3=0,ans1=0,ans2=0;
        for(int i=1; i<=n; i++)
        {
            int nummax=0;
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>a[i][2])
            {
                if(a[i][1]>a[i][3])
                {
                    nummax=a[i][1];//1>2 1>3
                    if(a[i][2]>a[i][3])
                    {
                        //1>2>3
                        c[i]=nummax-a[i][2];
                    }
                    else
                    {
                        //1>3>2
                        c[i]=nummax-a[i][3];
                    }


                }
                else
                {
                    nummax=a[i][3];//3>1>2
                    c[i]=nummax-a[i][1];
                }
            }
            else
            {
                if(a[i][2]>a[i][3])
                {
                    nummax=a[i][2];//2>1 2>3
                    if(a[i][1]>a[i][3])
                    {
                        //2>1>3
                        c[i]=nummax-a[i][1];
                    }
                    else
                    {
                        //2>3>1
                        c[i]=nummax-a[i][3];
                    }

                }
                else
                {
                    nummax=a[i][3];//3>2>1
                    c[i]=nummax-a[i][2];
                }

            }



            ans1=ans1+nummax;
            if(a[i][1]==nummax)
            {
                book[i]=1;
            }
            else if(a[i][2]==nummax)
            {
                book[i]=2;
            }
            else if(a[i][3]==nummax)
            {
                book[i]=3;
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(book[i]==1)
            {
                num1++;
            }
            else if(book[i]==2)
            {
                num2++;
            }
            else if(book[i]==3)
            {
                num3++;
            }
        }
        int nummax=0;
        if(num1>num2)
        {
            if(num1>num2)
            {
                nummax=num1;
            }
            else
            {
                nummax=num3;
            }
        }
        else
        {
            if(num2>num3)
            {
                nummax=num2;
            }
            else
            {
                nummax=num3;
            }

        }
        if(nummax>n/2)
        {
             sort(c+1,c+n+1);
             int cz=c[n]-c[1];
             cout<<ans1-1<<endl;


        }
        else
        {
            cout<<ans1<<endl;
        }

    }





    return 0;
}
