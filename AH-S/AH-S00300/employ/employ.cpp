#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;
string s;
int a[20],idx[20];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    cin>>s;
    if(n<=20){
        int ans=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) idx[i]=i;
        do{
            int cnt=0,fail=0;
            for(int i=0;i<n;i++){
                //cout<<s[i]<<" "<<idx[i]<<endl;
                if(s[i]=='0'){
                    fail++;
                } else {
                    if(fail>=a[idx[i+1]]) fail++;
                    else cnt++;
                }
            }
            if(cnt>=m) ans++;
        }while(next_permutation(idx+1,idx+1+n));
        cout<<ans<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
