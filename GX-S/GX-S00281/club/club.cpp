#include<iostream>
#include<math>
using namespace std;
int n;
double m;
int a,b,c;
int x=0,y[5]=[0,0,0,0,0];
int main()
{cin>>n;
for(int i=1;i<=n;i++)
    {
        cin>>m;
        for(int u=1;u<=m;u++)
        {
            cin>>a>>b>>c;
            if(a>=b&&y[1]<=0.5*m)
            {
                if(a>=c)
                    x+=a;
                    y[1]+=1;
                else if(y[3]<=0.5*m)
                    x+=c;
                    y[3]+=1;
                else
                {
                    x+=b;
                    y[3]+=1
                }
            }
            else
            {
                if(b>=c&&y[2]<=0.5*m)
                {
                    x+=b;
                    y[2]+=1;
                }
                else
                {

                    x+=c;y[3]+=1;
                }
            }
        }
        cout<<x<<endl;
        x=0;
    }
    return 0;
}
