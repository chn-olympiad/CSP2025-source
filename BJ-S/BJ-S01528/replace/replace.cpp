#include<bits/stdc++.h>
using namespace std;
int n,q;
bool tong[5000005];
string s1[200005],s2[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<endl;
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int xb=0;
            for(int j=0;j<t1.size();j++){
                if(xb==s1[i].size()){
                    tong[j-s1[i].size()]=1;
                    xb=0;
                }
                if(t1[j]==s1[i][xb]){
                    xb++;
                }
                else{
                    xb=0;
                }
            }
            int cnt=0;
            for(int j=0;j<t1.size();j++){
                if(cnt==s1[i].size()){
                    if(t1==t2){
                        ans++;
                    }
                    cnt--;
                    int ooo=j-1;
                    while(cnt>=0){
                        swap(t1[ooo],s2[i][cnt]);
                        cnt--;
                        ooo--;
                    }
                    cnt=0;
                }
                if(tong[j]==1){
                    while(cnt<s2[i].size()){
                        swap(t1[j],s2[i][cnt]);
                        j++;
                        cnt++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
