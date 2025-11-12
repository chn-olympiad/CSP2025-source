#include<bits/stdc++.h>
using namespace std;
int t;
int a[100005][10];
bool flag = true,f = true;
bool cmp(int x,int y){
    if(x>y)return true;
    return false;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        int sum[100005];
        int num1[2][100005],num2[2][100005];
        cin>>n;
        int x = 0,y = 0;
        for(int i = 0;i<n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=a[i][3]||a[i][2] != 0){
                    flag = false;
            }
            sum[i] = a[i][1];
            if(a[i][3]!=0){
                f = false;
            }
            if(a[i][1]>a[i][2]){
                num1[1][x] = a[i][1]-a[i][2];
                num1[2][x] = i;
                x++;
            }
            else{num2[1][y] = a[i][2]-a[i][1];y++;num2[2][y-1] = i;}
        }
        if(n == 2){
            int maxsum;
            for(int i = 1;i<=3;i++){
                for(int j = 1;j<=3;j++){
                    if(j == i)continue;
                    else{
                        maxsum = max(maxsum,a[0][i]+a[1][j]);
                    }
                }
            }
            cout<<maxsum<<endl;continue;
        }
        sort(sum,sum+n,cmp);
        int ans=0;
        if(flag){
                f = false;

            for(int i = 0;i<n/2;i++){
                ans+=sum[i];
            }
            cout<<ans<<endl;
        }
        if(f){
            int anss = 0;
            if(x>y){
                sort(num1[1],num1[1]+x);
                for(int i = 0;i<y;i++){
                    anss+=a[num2[2][i]][2];
                }
                for(int i = 0;i<(x-y)/2;i++){
                    anss-=num1[1][i];
                }
                for(int i = 0;i<x;i++){
                    anss+=a[num1[2][i]][1];
                }
                cout<<anss<<endl;
            }
            else{
                sort(num2[1],num2[1]+y);
                for(int i = 0;i<x;i++){
                    anss+=a[num1[2][i]][1];
                }
                for(int i = 0;i<(y-x)/2;i++){
                    anss-=num2[1][i];
                }
                for(int i = 0;i<y;i++){
                    anss+=a[num2[2][i]][2];
                }
                cout<<anss<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
