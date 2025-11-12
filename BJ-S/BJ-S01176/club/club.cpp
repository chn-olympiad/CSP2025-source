/*#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],m[100005][3][3],p[100005],jt[100005];
int main(){
    int s;
    cin >> s;
    int sum = 0,sum1 = 0,sum2 = 0,sum3 = 0;
    for(int i = 0;i < s;i++){
        cin >> a[i] >> b[i] >> c[i];
        p[i] = max(a[i],max(b[i],c[i]));
        m[i][0][1] = b[i]-a[i];
        m[i][0][2] = c[i]-a[i];
        m[i][1][2] = c[i]-b[i];
        m[i][1][0] = a[i]-b[i];
        m[i][2][0] = a[i]-c[i];
        m[i][2][1] = b[i]-c[i];
        sum+=p[i];
        if(sum == a[i]){
            sum1++;
            jt[i] = 0;
        }else if(sum == b[i]){
            sum2++;
            jt[i] = 1;
        }else{
            sum3++;
            jt[i] = 2;
        }
    }
    if((sum1>(s/2))||(sum2>(s/2))||(sum3>(s/2))){
        for(int i = 0;i < s;i++){
            if((sum1>(s/2))){

            }
        }
    }


    return 0;
}*/
/*#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],dp[100005][3][3][3];
int main(){
    int s;
    cin >> s;
    int o=0,p=0,q=0;

    for(int i = 0;i < s;i++){
        cin >> a[i] >> b[i] >> c[i];
        if(i)
    }
    if((sum1>(s/2))||(sum2>(s/2))||(sum3>(s/2))){
        for(int i = 0;i < s;i++){
            if((sum1>(s/2))){

            }
        }
    }


    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int s;
    cin >> s;
    for(int i = 0;i < s;i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    sort(a,a+s);
    int sum = 0;
    for(int i = s/2 + 1;i <= s;i++){
        sum+=a[i];
    }
    cout << sum;
    return 0;
}
