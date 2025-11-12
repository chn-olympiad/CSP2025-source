#include <bits/stdc++.h>

using namespace std;
int n,t,sum=0,pop=20005;
int a1[20005],a2[20005],a3[20005];
int b1,b2,b3;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a1[i]>>a2[i]>>a3[i];
            if(a2[i]==0 && a3[i]==0 && a1[i]!=0){
                sum+=a1[i];
                b1++;
            }

        }
        if(b1<=n/2){
            cout<<sum<<endl;
            return 0;
        }else{
            int x=1;
            while(b1!=n/2){
                b1--;
                sort(a1+1,a1+n+1);
                sum-=a1[x];
                x++;

            }
            cout<<sum<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
