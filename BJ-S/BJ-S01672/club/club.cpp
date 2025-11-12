#include <bits/stdc++.h>
using namespace std;

int t;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    while (t--){
        int n,cnt=0;
        cin >> n;
        for (int i=0;i<n;i++){
            int first[i],second[i],third[i];
            cin >> first[i] >> second[i] >> third[i];

            if (second[0]==0 && third[0]==0){
                sort (first,first+n);
                for (int i=n-1;i>=(n/2);i--){
                    cnt+=first[i];
                }
                cout << cnt << endl;
            }
            else if(n==2){
                int maxx=-1;
                maxx=max(maxx,first[0]+second[1]);
                maxx=max(maxx,first[0]+third[1]);
                maxx=max(maxx,second[0]+third[1]);
                maxx=max(maxx,first[1]+second[0]);
                maxx=max(maxx,first[1]+third[0]);
                maxx=max(maxx,second[1]+third[0]);
                cout << maxx << endl;
            }
        }
    }

    return 0;
}
