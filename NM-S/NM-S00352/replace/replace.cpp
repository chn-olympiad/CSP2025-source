#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    int arr[10005];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<int>a(n+2,0);
    for(int i=0;i<=n;i++){
        a[i]=arr[i]-arr[i-1];
    }
    char s1,s2;
    for(int i=1;i<=q;i++){
        cin>>s1>>s2;
        char t1,t2;
        for(int j=1;j<=q;j++){
            cin>>t1>>t2;
            int f;
            cin>>f;
            f=t1;
            t1=t2;
            f=t2;
            if(j<=q){
                cout<<f<<endl;
            }else{
                cout<<"2"<<endl;
                cout<<"0"<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
