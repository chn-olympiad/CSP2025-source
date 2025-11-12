int t,n;
int nm;
int ch;
int a[100][100],c1[100];
int k,m11,m12=1,m21,m22=1,m31,m32=1;
int club(int a[100][100]);
int m1(int a[100][100]);
int m2(int a[100][100]);
int m3(int a[100][100]);
int main()
{
    freopen("replace.in","r"stdin);
    freopen("replace.out","w",stdout);
    int h;
    int a1[100];
    cin>>t>>h;
    cin>>a;
    for(int s=0;s<t;s++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>a[i][j];
            }
        }
            for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                nm=n;
                a1[i]=club(a);
            }
        }
    }for(int i=0;i<=t+h/2;i++)
    {

        cout<<k
    }
    return 0;
}
int club(int a[100][100])
{
    int mnn;
    for(int i=0;i<nm;i++)
    {
        for(int j=0;j<3;j++)
        {
        }

    }

      return mnn;
}


int m1(int a[100][100])
{
    int mae=0;
    int k=0;
    int b1[100];

    for(int i=0;i<nm;i++)
    {
        if(a[i][1]>mae)
        {
            mae=a[i][1];
            k++;
        }
    }
    m11+=k;
    if(m11<=n/2)
    {
        for(int i=0;i<nm;i++)
        {
            if(a[i][1]==mae)
            {
                for(int j=i;j<nm;j++)
                {
                    a[i][1]=a[i+m12][1];
                    m12++;
                }
                nm--;
            }
        }
        ch+=(m12-1)*mae;
    }
    else
        {
            for(int i=0;i<nm;i++)
            {
                for(int j=0;j<3;j++)
                {
                    m2(a);
                }

            }
        }
              if(nm==0)
        {
            return ch;
        }


}


int m2(int a[100][100])
{
    int mae1=0;
    int k1=0;
    int b11[100];

    for(int i=0;i<nm;i++)
    {
        if(a[i][1]>mae1)
        {
            mae1=a[i][1];
            k1++;
        }
    }
    m21+=k1;
    if(m21<=n/2)
    {
        for(int i=0;i<nm;i++)
        {
            if(a[i][2]==mae1)
            {
                for(int j=i;j<nm;j++)
                {
                   a[i][2]=a[i+m22][2];
                    m22++;
                }
                nm--;
            }
        }
        ch+=(m22-1)*mae1;
    }
    else
        {
            for(int i=0;i<nm;i++)
            {
                for(int j=0;j<3;j++)
                {
                    m3(a);
                }

            }

        }
           if(nm==0)
        {
            return ch;
        }

}


int m3(int a[100][100])
{
    int mae3=0;
    int k3=0;
    int b3[100];

    for(int i=0;i<nm;i++)
    {
        if(a[i][3]>mae3)
        {
            mae3=a[i][1];
            k3++;
        }
    }
    m31+=k3;
    if(m31<=n/2)
    {
        for(int i=0;i<nm;i++)
        {
            if(a[i][3]==mae3)
            {
                for(int j=i;j<nm;j++)
                {
                    a[i][3]=a[i+m32][3];
                    m32++;
                }
                nm--;
            }
        }
        ch+=(m32-1)*mae3;
    }
    else
        {
            for(int i=0;i<nm;i++)
            {
                for(int j=0;j<3;j++)
                {
                    m1(a);
                }

            }
        }
        if(nm==0)
        {
            return ch;
        }

}
