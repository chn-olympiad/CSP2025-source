#include<bits/stdc++.h>
using namespace std;
int n[15][15];
int a[105];
int b=0,d=0,c;


 int main()
{
cin>>b>>d;
for(int i=1;i<=b*d;i++){
    cin>>a[i];
}
c=a[1];
sort(a+1,a+b*d+1);
for(int i=1;i<=b*d;i++){
    if(a[i]==c)
    {int m=0;
    for(int i=1;i<=d;i++)
    {if(i%2==1)
    {for(int j=1;j<=b;i++){m++;
    if(m=c)
    {cout<<i<<j;
    freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
        return 0;

    }

}
    }
else
{for(int j=b;j>=b;i++){m++;
    if(m=c)
    {cout<<i<<j;
    freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
        return 0;

    }
}

}

}


    }
}
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
return 0;
}
