#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int b=n*m;
    int s[b];
    for(int i=0;i<b;i++)
    {
        cin>>s[i];
    }
    int ss=s[0],ans=0;
    sort(s,s+b);
    for(int i=b-1;i>=0;i--)
    {
        if(ss==s[i])
        {
            ans=b-i;
            break;
        }
    }
    int lie=(ans-1)/n+1,yu=ans%n;
    if(yu==0) yu=n;
    cout<<ans<<endl;
    if(lie%2==1)
    {
        cout<<lie<<" "<<yu;
    }
    else{
        cout<<lie<<" "<<n-yu+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
