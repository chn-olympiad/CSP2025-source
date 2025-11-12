#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;

    for(int a = 1 ; a <=t ; a++){
        int n;
     cin >> n;
        int ans = 0;
        for(int i = 0 ; i< n; i++){

            int q;
            int w;
            int e;
            cin>>q>>w>>e;
            if(q>=w){
                if(q>=e){
                    ans = ans + q;
                }else{
                ans = ans + e;
                }
            }else if(w>=e){
                ans = ans + w;
            }else{
                ans = ans + e;
            }

        }
    cout<<ans<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
