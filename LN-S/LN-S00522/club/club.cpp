#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
bool flag = true;
int t,n,maxn,num1,num2,num3,maxn1,maxn2,maxn3,smaxn1,smaxn2,smax3,fmaxn1,fmaxn2,fmaxn3,sum = 0;
int a[100005][5];
int b[100005];
int c[100005];
int d[100005];
int cnt = 0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int i = 1;i<=t;i++){
        cin >> n;
        sum = 0;
        for(int j = 1;j<=n;j++){
            cin >> a[j][0] >> a[j][1] >> a[j][2];
            maxn = max(a[j][0],max(a[j][1],a[j][2]));
            if(a[j][0] == maxn){
                a[j][3] = 0;
                if(a[j][1]>a[j][2]){
                    a[j][4] = a[j][1];
                }else{
                    a[j][4] = a[j][2];
                }
                num1++;
            }else if(a[j][1] == maxn){
                a[j][3] = 1;
                if(a[j][0]>a[j][2]){
                    a[j][4] = a[j][0];
                }else{
                    a[j][4] = a[j][2];
                }
                num2++;
            }else{
                a[j][3] = 2;
                if(a[j][1]>a[j][0]){
                    a[j][4] = a[j][1];
                }else{
                    a[j][4] = a[j][0];
                }
                num3++;
            }
        }
        if(num1>n/2){
            flag = false;
            for(int j = 1;j<=n;i++){
                if(a[j][3] == 0){
                    b[j] == a[j][0];
                }
            sort(b+1,b+1+n);
            }
        }else if(num2>n/2){
            flag = false;
            for(int j = 1;j<=n;i++){
                if(a[j][3] == 1){
                    c[j] == a[j][1];
                }
            }
            sort(c+1,c+1+n);
        }
        else if(num3>n/2){
            flag = false;
            for(int j = 1;j<=n;i++){
                if(a[j][3] == 2){
                    d[j] = a[j][2];
                }
            }
            sort(d+1,d+1+n);
        }
        if(flag){
            for(int j = 1;i<=n;j++){
                sum += a[j][a[j][3]];
            }
        }else{
            if(num1>n/2){
                cnt = 0;
                int l = 0;
                for(int j = 1;j<=n/2;j++){
                    if(b[j] == b[n/2]){
                        l = j;
                        break;
                    }
                }
                for(int j = n;j>n/2;j--){
                    sum+=b[j];
                }
                for(int j = 1;j<=n;j++){
                    if(a[j][3] == 0 && a[j][a[j][3]]<b[n/2]){
                        sum+=a[j][a[j][4]];
                    }else if(a[j][3] == 0 && a[j][a[j][3]] == b[n/2] && cnt<=n/2-l+1){
                        sum+=a[j][a[j][3]];
                        cnt++;
                    }else if(a[j][3] != 0){
                        sum+=a[j][a[j][3]];
                    }
                }
            }
            if(num2>n/2){
                cnt = 0;
                int l = 0;
                for(int j = 1;j<=n/2;j++){
                    if(c[j] == c[n/2]){
                        l = j;
                        break;
                    }
                }
                for(int j = n;j>n/2;j--){
                    sum+=c[j];
                }
                for(int j = 1;j<=n;j++){
                    if(a[j][3] == 0 && a[j][a[j][3]]<c[n/2]){
                        sum+=a[j][a[j][4]];
                    }else if(a[j][3] == 0 && a[j][a[j][3]] == c[n/2] && cnt<=n/2-l+1){
                        sum+=a[j][a[j][3]];
                        cnt++;
                    }else if(a[j][3] != 0){
                        sum+=a[j][a[j][3]];
                    }
                }
            }
            if(num3>n/2){
                cnt = 0;
                int l = 0;
                for(int j = 1;j<=n/2;j++){
                    if(d[j] == d[n/2]){
                        l = j;
                        break;
                    }
                }
                for(int j = n;j>n/2;j--){
                    sum+=d[j];
                }
                for(int j = 1;j<=n;j++){
                    if(a[j][3] == 0 && a[j][a[j][3]]<d[n/2]){
                        sum+=a[j][a[j][4]];
                    }else if(a[j][3] == 0 && a[j][a[j][3]] == d[n/2] && cnt<=n/2-l+1){
                        sum+=a[j][a[j][3]];
                        cnt++;
                    }else if(a[j][3] != 0){
                        sum+=a[j][a[j][3]];
                    }
                }
            }
        }
        cout << sum << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
