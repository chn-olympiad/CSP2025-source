#include <iostream>
#include <algorithm>
using namespace std;

int cmp(int x,int y){
    return x<y;
}
int n,a[5005],cnt;

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=3;i<=n;i++){
        int sum=0;
        for(int j=i-1;j>=1;j--){
            sum+=a[j];
            if(sum>a[i]){
                cnt+=j;
                break;
            }
        }
    }
    for(int i=4;i<=n;i++){
        int sum=0;
        for(int j=1;j<i-1;j++){
            sum+=a[j];
            if(sum>a[i]){
                cnt+=(i-j)*(i-j);
                break;
            }
        }
    }


    cout << cnt%998244353;
    return 0;
}
