#include<bits/stdc++.h>
using namespace std;
int a[500010];int n,k,V=1e9;
void f(int i,int s)
{
     if(s>k||i>n)return;
    if(s^a[i]==k)
    {  // cout<<"p";
        V=min(V,i);
        return;
    }
  //  cout<<"Z";
     f(i+1,s);
    //cout<<s;
    f(i+1,s^a[i]);
    return;

}
int main()
{
  freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);



    cin>>n>>k;
    int f1=0;
    int s=0,s1=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];

        if(a[i]==1)
        {
            s++;
        }
        else if(a[i]==0)
        {
            s1++;
        }
        else{
            f1=1;
        }
    }
    if(k==1&&f1==0)
    {
        cout<<min(s,s1);
    }
    else if(k==0&&f1==0){
        cout<<s1/2+s/2;
    }
    else{
         // cout<<"XXX";
    int p=1,ans=0;
    while(p<=n)
    {
        f(p,0);
        if(V==1e9)
        {
            break;
        }
        p=V+1;
        ans++;
       // cout<<p;
       //cout<<p;
        V=1e9;
    }
    cout<<ans;
    }

    return 0;
}
