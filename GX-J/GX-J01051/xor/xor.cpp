#include<iostream>
using namespace std;
long long n,k;
long long a[501000];
long long cnt = 0;
bool flag[501000];
int ccl(long long s,long long e){
    if(s == e)return a[s];
    int ret = a[s];
    for(long long i = s + 1;i <= e;i++){
        ret ^= a[i];
    }return ret;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i = 0;i < n;i++){
        cin>>a[i];
    }int ind = 0;
    for(long long limit = 0;limit < n;limit++){
        for(long long i = 0;i <= limit;i++){
            for(long long j = i;j <= limit;j++){
                if(ccl(i,j) == k){
                    bool p = true;
                    for(long long l = i;l <= j;l++){
                        if(flag[l]){
                            p = false;
                            break;
                        }
                    }if(p){
                        cnt++;
                        for(long long l = i;l <= j;l++){
                            flag[l] = true;
                        }
                    }short st = 17;
                    if(j - i >= st)i = j - st;
                    break;
                }
            }
        }
    }cout<<cnt;
    return 0;
}
