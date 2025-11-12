#include<bits/stdc++.h>
using namespace std;
int abc[100010];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a,b;
    char[505];
    for(int i=0;i<n;i++){
        cin>>c;
    }
    for(int i=0;i<n;i++){
        cin>>a>>b;
    }
    long long sum=1;
    int N=998344353;
    for(int i=n;i>1;i++){
        sum=sum*i;
        sum=sum%N;
    }
    cout<<sum<<endl;
    return 0;
}
