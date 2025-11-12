#include<bits/stdc++.h>
using namespace std;
string s;
int p[1000001];
long long n,a,i,j;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    a=0;
    for(i=0;i<=n-1;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
          {
              a++;
              p[a]=s[i]-48;
          }
    }
    for(i=1;i<=a;i++)
        for(j=i+1;j<=a;j++)
        {
            if(p[i]<p[j])
                swap(p[i],p[j]);
        }
    for(i=1;i<=a;i++)
        cout<<p[i];
        fclose(stdin);
        fclose(stdout);
    return 0;
}
