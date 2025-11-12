#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int b,c,d,e,f,g,h,a1,a2,a3;
    int a4,ax1,ax2,ax3,ax4,ax5,ax6;
    int b1,b2,b3,b4,b5,b6,b7;
    cin>>b>>c>>d>>e>>f>>g>>h>>a1>>a2;
    cin>>a3>>a4>>ax1>>ax2;
    cin>>ax3>>ax4>>ax5>>ax6;
    cin>>b1>>b2>>b3>>b4>>b5>>b6>>b7;
    string s;
    cin>>s;
    int a[s.size()];
    for (int i=0;i<s.size();i++)
    {
        a[i]=-10000;
    }
    int n=0;

    for (int i=0;i<s.size();i++){
        if(s[i]<='9' && s[i]>='0'){
            a[i]=s[i];
            n++;
        }

    }
    for (int i=1;i<=n;i++)
        {
        int maxn=-10,m=0;
        for (int j=0;j<s.size();j++){
            if(maxn<=a[j]-48){
                maxn=a[j]-48;
                m=j;
            }
        }
        if(maxn!='0') cout<<maxn+9;
        a[m]=-1;
        int k=0;
        for (int j=0;j<s.size();j++)
        {
            if(a[i]>=0)
            {
                k=1;
            }
        }
        if(k=0) break;
  }
 return 0;
}
