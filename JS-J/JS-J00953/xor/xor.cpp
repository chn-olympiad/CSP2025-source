#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[555555];
int s[555555];
map<int,int> m;
int n,k;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0) s[i]=a[i];
        else s[i]=s[i-1] xor a[i];
    }
    m[0]=1;
    int ans=0;
    for(int i=0;i<n;i++){
        int need=0;
        for(int j=0;j<=21;j++){
            if(s[i] & (1<<j)){
                if(k & (1<<j)) need+=0;
                else need+=(1<<j);
            }
            else if(k & (1<<j)) need+=(1<<j);
        }
        if(m[need]){
            ans++;
            m.clear();
            m[s[i]]=1;
        }
        else m[s[i]]=1;
    }
    cout<<ans<<endl;
    return 0;
}
/*
JJJJJJJJJJ   RP++
    JJ       RP++
    JJ       RP++
    JJ       RP++
    JJ       RP++
J   JJ       RP++
JJ  JJ       RP++
 JJJJ        RP++
*/
//09:34 AC
