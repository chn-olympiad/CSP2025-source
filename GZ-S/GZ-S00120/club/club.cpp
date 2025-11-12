//GZ-S00120 赫章西城区高级中学 夏欣宇
#include <bits/stdc++.h>
using namespace std;
int t,n,sum;
int a[10005],ma,b[1003],;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[j];
                if(a[j]>=ma){
                    ma=a[j];
                    sum+=a[j];
                }

            }


        }
        cout<<sum<<endl;

    }


	return 0;
}
