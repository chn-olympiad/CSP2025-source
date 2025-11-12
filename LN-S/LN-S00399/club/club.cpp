#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,a = 0,ans = 0;
    cin>>t;
    while(a<t){
        int n,c,d;
        cin>>n;
        int club1[n + 1],zan1;
        for (int i = 1;i<=n;i++){
            cin>>club1[i]>>c>>d;
        }
        for (int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(club1[i] > club1[j]){
                    zan1 = club1[j];
                    club1[j] = club1[i];
                    club1[j] = club1[i];
                    club1[i] = zan1;
                }
            }
        }
        int e;
        e = n / 2;
        for(int i = 0;i <= e;i++){
            ans += club1[i];
        }
        a++;
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
