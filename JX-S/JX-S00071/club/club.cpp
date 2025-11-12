#include <iostream>
#include <algorithm>
using namespace std;
int r,n;
long long ans;
int dp;
int co[5]={0};
int x,y,z;
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> r;
    for(int i=0;i < r;i++){
        cin >> n;
        for(int j=1 ;j <= n; j++){
            cin >> x >> y >> z;
            dp=max(x,z);
            dp=max(dp,y);
            if (dp==x && dp!=y && dp!=z) {
                co[1]++;
                if (co[1] <= n/2)
                    ans+=dp;
                else{
                    co[1]--;
                    ans+=max(y,z);
                    if (dp==y && dp!=z)
                        co[2]++;
                    else{
                        co[3]++;
                        }
                        ans+=dp;
                    }
                }
            if (dp==y && dp!=x && dp!=z) {
                co[2]++;
                if (co[2] <= n/2)
                    ans+=dp;
                else{
                    co[2]--;
                    ans+=max(x,z);
                    if (dp==x && dp!=z)
                        co[1]++;
                    else{
                        co[3]++;
                        }
                        ans+=dp;
                    }
                }
            if (dp==z && dp!=x && dp!=y) {
                co[3]++;
                if (co[3] <= n/2)
                    ans+=dp;
                else{
                    co[3]--;
                    dp=max(x,y);
                    if (dp==x && dp!=y)
                        co[1]++;
                    else{
                        co[2]++;
                        }
                        ans+=dp;
                    }
                }
        }
        cout << ans << endl;
        ans=0;
    }
    return 0;
}

