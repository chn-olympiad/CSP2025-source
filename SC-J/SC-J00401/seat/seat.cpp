#include <bits/stdc++.h>
using namespace std;

int n,m;
pair<int,int> arr[103];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n * m;i++){
        scanf("%d",&arr[i].first);
        arr[i].second = i;
    }
    sort(arr + 1,arr + n * m + 1,[](pair<int,int> a,pair<int,int> b){ return a.first > b.first; });
    int ranks;
    for(int i = 1;i <= n * m;i++){
        if(arr[i].second == 1){
            ranks = i;
            break;
        }
    }
    int h = (ranks % n == 0 ? ranks / n : ranks / n + 1);
    int l;
    if(h % 2 == 1){
        l = (ranks % n == 0 ? n : (ranks % n));
    }else{
        l = (ranks % n == 0 ? 1 : n - (ranks % n) + 1);
    }
    printf("%d %d",h,l);
    return 0;
}