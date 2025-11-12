#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[114514];
bool flag[114514];
int main()
{
    //₡₡₤
    //¢¢£
    //€€₣
    //i hate ₯!!
    //i hate ₠!!
    //i hate ₩₳!!
    // i hate ₸⎩Ē!!
    //i love ₳€!!!!!!!!!!
    //₣
    //Ũ
    //₵
    //₭
    //
    //€
    //₡
    //₣
    // Hei Hei Fa Xian Bu Liao Ba hhhhhhhhhhhhhh
    #ifndef debug
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    #endif // debug
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
        int cnt=0;
        for(int i=1;i<=n;i++)
            {
                if(a[i]==k&&!flag[i])
                {
                    flag[i]=1;
                    cnt++;
                }
                else if(i<n)
                {
                    if((a[i]^a[i+1])==k&&!flag[i]&&!flag[i+1])
                    {
                        flag[i]=1;
                        flag[i+1]=1;
                        cnt++,i++;
                    }
                }
            }
        cout<<cnt;
    return 0;
}
// Wo Yao Shang Mi Huo Xing Wei Da Shang
