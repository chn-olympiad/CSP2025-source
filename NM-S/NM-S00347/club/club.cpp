#include <bits/stdc++.h>

using namespace std;
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
    int t=0;
    int add=0;
    cin>>t;
    int n=0;
    while(t--){
        add=0;
        n=0;
        cin>>n;
        int people[n][3];
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++)
            cin>>people[i][j];
        }
        for(int i1=0;i1<n;i1++){

               add+=max(people[i1][0],max(people[i1][1],people[i1][2]));

        }

 cout<<add<<endl;
    }

    return 0;
}
