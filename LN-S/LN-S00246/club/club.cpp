#include <iostream>
#include <cstdio>
using namespace std;
int t,n,cnt=0,a1[100001],a2[100001],a3[100001],a4[100001],num1=0,num2=0,num3=0;
int dfs(int num,int cnt,int num1,int num2,int num3)
{
    int cnt1=0,cnt2=0,cnt3=0;
    if (num == n)
    {
        return cnt;
    }
    if (num1<n/2){
        num1++;
        cnt+=a1[num];
        cnt1 = dfs(num+1,cnt,num1,num2,num3);
        cnt-=a1[num];
        num1-=1;
    }
    if (num2<n/2){
        num2++;
        cnt+=a2[num];
        cnt2 = dfs(num+1,cnt,num1,num2,num3);
        cnt-=a2[num];
        num2-=1;
    }
    if (num3<n/2){
        num3++;
        cnt+=a3[num];
        cnt3 = dfs(num+1,cnt,num1,num2,num3);
        cnt-=a3[num];
        num3-=1;
    }
    if (cnt1>=cnt2){
        if (cnt1>=cnt3){
            return cnt1;
        }
        if (cnt3>cnt1){
            return cnt3;
        }
    }
    if (cnt1<cnt2){
        if (cnt2>=cnt3){
            return cnt2;
        }
        if (cnt2<cnt3){
            return cnt3;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for (int i = 0;i < t;i++)
    {
        cin >> n;
        for (int j = 0;j < n;j++)
        {
            cin >> a1[j] >> a2[j] >> a3[j];
        }
        cout << dfs(0,0,0,0,0) << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
