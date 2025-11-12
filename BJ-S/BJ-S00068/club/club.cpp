#include <bits/stdc++.h>
using namespace std;
long long t,n,a,b,c,cnt1,cnt2,cnt3,sum;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        vector<long long> minn1;
        vector<long long> minn2;
        vector<long long> minn3;
        sum=cnt1=cnt2=cnt3=0;
        for(int i=1;i<=n;i++){
            cin >> a >> b >> c;
            if(a>=b&&b>=c){
                sum+=a;
                cnt1++;
                minn1.push_back(a-b);
            }
            else if(a>=c&&c>=b){
                sum+=a;
                cnt1++;
                minn1.push_back(a-c);
            }
            else if(b>=a&&a>=c){
                sum+=b;
                cnt2++;
                minn2.push_back(b-a);
            }
            else if(b>=c&&c>=a){
                sum+=b;
                cnt2++;
                minn2.push_back(b-c);
            }
            else if(c>=a&&a>=b){
                sum+=c;
                cnt3++;
                minn3.push_back(c-a);
            }
            else if(c>=b&&b>=a){
                sum+=c;
                cnt3++;
                minn3.push_back(c-b);
            }
        }
        if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
            cout << sum << endl;
        }
        else if(cnt1>n/2){
            sort(minn1.begin(),minn1.end());
            for(int i=0;i<cnt1-n/2;i++)sum-=minn1[i];
            cout << sum << endl;
        }
        else if(cnt2>n/2){
            sort(minn2.begin(),minn2.end());
            for(int i=0;i<cnt2-n/2;i++)sum-=minn2[i];
            cout << sum << endl;
        }
        else if(cnt3>n/2){
            sort(minn3.begin(),minn3.end());
            for(int i=0;i<cnt3-n/2;i++)sum-=minn3[i];
            cout << sum << endl;
        }
    }
    return 0;
}