#include <bits/stdc++.h>
using namespace std;

int t,n;

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;
    while (t--){
        vector<int> v1,v2,v3;
        cin>>n;
        int skp=0;
        int skpz=0;
        int sum1=0,sum2=0,sum3=0;
        for (int i=1;i<=n;i++){
            int a1,a2,a3;
            cin>>a1>>a2>>a3;
            int maxz=max(max(a1,a2),a3);
            int minz=min(min(a1,a2),a3);
            int midz=a1+a2+a3-maxz-minz;
            if (maxz==midz){
                skp++;
                skpz+=maxz;
            }
            else{
                if (maxz==a1){
                    v1.push_back(maxz-midz);
                    sum1+=maxz;
                }
                else if (maxz==a2){
                    v2.push_back(maxz-midz);
                    sum2+=maxz;
                }
                else{
                    v3.push_back(maxz-midz);
                    sum3+=maxz;
                }
            }
        }
        if (v1.size()<=n/2 and v2.size()<=n/2 and v3.size()<=n/2){
            cout<<sum1+sum2+sum3+skpz<<"\n";
            continue;
        }
        int lans=sum1+sum2+sum3+skpz;
        if (v1.size()>n/2){
            sort(v1.begin(),v1.end());
            int needel=v1.size()-n/2;
            for (int i=0;i<needel;i++){
                lans-=v1[i];
            }
        }
        if (v2.size()>n/2){
            sort(v2.begin(),v2.end());
            int needel=v2.size()-n/2;
            for (int i=0;i<needel;i++){
                lans-=v2[i];
            }
        }
        if (v3.size()>n/2){
            sort(v3.begin(),v3.end());
            int needel=v3.size()-n/2;
            for (int i=0;i<needel;i++){
                lans-=v3[i];
            }
        }
        cout<<lans<<"\n";
    }
    // system("grep VmPeak /proc/$PPID/status");
    return 0;
}