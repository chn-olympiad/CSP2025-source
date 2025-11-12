#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int n;
char s[N];
multiset<int,greater<int>>st;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s),n=strlen(s);
    for(int i=0;i<n;i++){
        if(0<=s[i]-'0' && s[i]-'0'<=9){
            st.insert(s[i]-'0');
        }
    }
    //cout<<n<<" "<<st.size();
    for(int i:st){
        printf("%d",i);
    }
    puts("");
    return 0;
}
//#Shang4Shan3Ruo6Shui4
