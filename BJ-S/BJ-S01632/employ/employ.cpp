#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=998244353;
int n,m,ans=0,peo[11];
string s;
bool check(int a[10]){
    int ju=0,cnt=0;
    for(int i=1;i<=10;i++){
        if(peo[a[i]]>ju&&peo[a[i]]==1){
            cnt++;
        }
    }
    return cnt>=m;
}
int main(){
    freopen("employ1.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    s=" "+s;
    for(int i=1;i<=10;i++){
        cin>>peo[i];
    }

    for(int a=1;a<=10;a++){
        for(int b=1;b<=10;b++){
            if(b==a)continue;
            for(int c=1;c<=10;c++){
                if(c==a||c==b)continue;
                for(int d=1;d<=10;d++){
                    if(d==a||d==b||d==c)continue;
                    for(int e=1;e<=10;e++){
                        if(e==a||e==b||e==c||e==d)continue;
                        for(int f=1;f<=10;f++){
                            if(f==a||f==b||f==c||f==d||f==e)continue;
                            for(int g=1;g<=10;g++){
                                if(g==a||g==b||g==c||g==d||g==e||g==f)continue;
                                for(int h=1;h<=10;h++){
                                    if(h==a||h==b||h==c||h==d||h==e||h==f||h==g)continue;
                                    for(int i=1;i<=10;i++){
                                        if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h)continue;
                                        for(int j=1;j<=10;j++){
                                            if(j==a||j==b||j==c||j==d||j==e||j==f||j==g||j==h||j==i)continue;
                                            for(int k=1;k<=10;k++){
                                                if(k==a||k==b||k==c||k==d||k==e||k==f||k==g||k==h||k==i||k==j){
                                                        continue;
                                                }
                                                int f[0,a,b,c,d,e,f,g,h,i,j,k];
                                                if(check(f)){
                                                        ans++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
