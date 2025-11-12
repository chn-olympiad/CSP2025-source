#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);


    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n+1,vector<int> (4));
        vector<int> a1(n/2);
        vector<int> b2(n/2);
        vector<int> c3(n/2);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        int m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(j==1){
                    m = j;
                }else{
                    m = a[i][j] > a[i][m] ? j : m;
                }
            }
            if(m == 1){
                a1.push_back(a[i][m]);
            }else if(m == 2){
                b2.push_back(a[i][m]);
            }else if(m == 3){
                c3.push_back(a[i][m]);
            }
        }
        int d = 0;
        for(int i=0;i<a1.size();i++){
            d = a1[i] + d;
        }
        for(int i=0;i<b2.size();i++){
            d = b2[i] + d;
        }
        for(int i=0;i<c3.size();i++){
            d = c3[i] + d;
        }
        cout<<d<<endl;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
