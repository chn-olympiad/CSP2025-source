#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long t=0,n=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i!=t;i++){
        cin>>n;
        long long aa[100005][4],ab[100005];
        long long a=0,b=0,c=0,ans=0;
        for(int j=0;j!=n;j++){
            cin>>aa[j][0]>>aa[j][1]>>aa[j][2];
            if(aa[j][0]>=aa[j][1]&&aa[j][0]>=aa[j][2]){
                a++;
                ans+=aa[j][0];
            }
            else if(aa[j][1]>=aa[j][2]&&aa[j][1]>=aa[j][0]){
                b++;
                ans+=aa[j][1];
            }
            else if(aa[j][2]>=aa[j][0]&&aa[j][2]>=aa[j][1]){
                c++;
                ans+=aa[j][2];
            }
        }
        if(a>n/2){
            long long f=0;
            for(int j=0;j!=n;j++){
                if(aa[j][0]>=max(aa[j][1],aa[j][2])){
                    ab[f]=aa[j][0]-max(aa[j][1],aa[j][2]);
                    f++;
                }
            }
            sort(ab,ab+f);
            for(int j=0;j!=a-n/2;j++){
                ans-=ab[j];
            }
        }
        else if(b>n/2){
            long long f=0;
            for(int j=0;j!=n;j++){
                if(aa[j][1]>aa[j][0]&&aa[j][1]>=aa[j][2]){
                    ab[f]=aa[j][1]-max(aa[j][0],aa[j][2]);
                    f++;
                }
            }
            sort(ab,ab+f);
            for(int j=0;j!=b-n/2;j++){
                ans-=ab[j];
            }
        }
        else if(c>n/2){
            long long f=0;
            for(int j=0;j!=n;j++){
                if(aa[j][2]>max(aa[j][1],aa[j][0])){
                    ab[f]=aa[j][2]-max(aa[j][1],aa[j][0]);
                    f++;
                }
            }
            sort(ab,ab+f);
            for(int j=0;j!=c-n/2;j++){
                ans-=ab[j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}