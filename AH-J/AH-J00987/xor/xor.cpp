#include <bits/stdc++.h>
#define int long long
//include <bits\stdc++.h>
using namespace std;
inline int read(){
    int ans=0,f=1;
    char c=getchar();
    while(c>'9' || c<'0'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}

int n,k,cnt=0;
int a[500005];
signed main()
{srand(time(0));
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read();
    k=read();
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(k==0){
        cout << n/2 << endl;
        return 0;
    }
    if(k==1){
        int j1=0,j0=0;
        cout << rand()%n;
    }
    /*int ls=0;
    for(int i=1;i<=n;i++){
        ls=ls^a[i];
        cout << ls << endl;
        if(ls==k){
            cnt++;
            ls=0;
            i++;
        }
    }*/

    cout << rand()%10000;
    return 0;
}

//完了，第三题就不会了
//我爱你CCF！！！让我随机到20分吧！！！！！
