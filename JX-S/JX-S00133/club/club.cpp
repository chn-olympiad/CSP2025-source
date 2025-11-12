#include<bits/stdc++.h>
using namespace std;
struct s{
    int a,b,c;
}aa[1000000];
int bb[1000000];
int aaa;
int bbb;
int ccc;
int sum2;
int sum;
bool a[1000000];
int m,n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    int n;
    cin >> t;
    while(t--){
        sum=0;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> aa[i].a >> aa[i].b >> aa[i].c;
            bb[i]=aa[i].a;
        }
        if(n==2){
            if(aa[1].a >= aa[1].b and aa[1].a >= aa[1].c){
                if(aa[1].b<aa[1].c){
                    sum2+=max(aa[2].a,aa[2].b)+aa[1].c;
                }else{
                    sum2+=max(aa[2].a,aa[2].c)+aa[1].b;
                }
                sum+=aa[1].a+max(aa[2].b,aa[2].c);
            }else if(aa[1].b >= aa[1].a and aa[1].b >= aa[1].c){
                if(aa[1].a<aa[1].c){
                    sum2+=max(aa[2].a,aa[2].b)+aa[1].c;
                }else{
                    sum2+=max(aa[2].b,aa[2].c)+aa[1].a;
                }
                sum+=aa[1].b+max(aa[2].a,aa[2].c);
            }else if(aa[1].c >= aa[1].a and aa[1].c >= aa[1].b){
                if(aa[1].b<aa[1].a){
                    sum2+=max(aa[2].c,aa[2].b)+aa[1].a;
                }else{
                    sum2+=max(aa[2].a,aa[2].c)+aa[1].b;
                }
                sum+=aa[1].c+max(aa[2].a,aa[2].b);
            }
            if(sum>sum2){
                cout << sum << '\0';
            }else{
                cout << sum2 << '\0';
            }
        }else if(n<=300){
            for(int i=1;i<=n;i++){
                if(aa[i].a >= aa[i].b and aa[i].a >= aa[i].c and aaa<=n/2){
                sum+=aa[i].a;
                aaa++;
            }else if(aa[i].b >= aa[i].a and aa[i].b >= aa[i].c and bbb<=n/2){
                sum+=aa[i].b;
                bbb++;
            }else if(aa[i].c >= aa[i].a and aa[i].c >= aa[i].b and ccc<=n/2){
                sum+=aa[i].c;
                ccc++;
            }
            }
            cout << sum << '\0';
        }else{
            sort(bb,bb+n);
            for(int i=n;i>=n/2;i--){
                sum+=bb[i];
            }
            cout << sum << '\0';
        }

    }

    return 0;
}
