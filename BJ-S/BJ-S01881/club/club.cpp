#include<bits/stdc++.h>
using namespace std;
const int  maxn = 1e5 + 6;
#define pii pair<int, int>
struct node{// pii: first = data, second = idx
    pii fir;
    pii sec;
    pii las;//f->s->l large->small
    bool phase=0;//phase = 0 fir -> sec phase = 1 sec -> las
}arr[maxn];
int n, a[maxn][6];
int cnt[10] = {0,0,0,0};
int ppl[10][maxn];//how many ppl here
int sum[6];// di i ge bu men de man yi du
bool flag[6] = {0, 0, 0, 0};// di i ge bu men shi fou manyuan
int T;
int ans=0;
bool cmp(int x, int y){
    if(arr[x].phase == 1)
        return arr[x].sec.first - arr[x].las.first < arr[y].fir.first - arr[y].sec.first;
    else if(arr[y].phase == 1)
        return arr[x].fir.first - arr[x].sec.first < arr[y].sec.first - arr[y].las.first;
    else if(arr[y].phase * arr[x].phase == 0)
        return arr[x].fir.first - arr[x].sec.first < arr[y].fir.first - arr[y].sec.first;
    return arr[x].sec.first - arr[x].las.first < arr[y].sec.first - arr[y].las.first;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= 3; i++)
            for(int j = 1; j <= n + 10; j++)
                ppl[i][j] = 0;
        memset(flag, 0, sizeof(flag));
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= n + 10; i++)
            arr[i].phase = 0;
        ans=0;
        cnt[1] = 0, cnt[2] = 0, cnt[3] = 0;
        int limit = n >> 1;
        for(int i = 1; i <= n; i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if(a[i][1] >= a[i][2]){
                if(a[i][2] >= a[i][3]){
                    arr[i].fir.first = a[i][1], arr[i].fir.second = 1;
                    arr[i].sec.first = a[i][2], arr[i].sec.second = 2;
                    arr[i].las.first = a[i][3], arr[i].las.second = 3;
                }
                else if(a[i][3] > a[i][1]){
                    arr[i].fir.first = a[i][3], arr[i].fir.second = 3;
                    arr[i].sec.first = a[i][1], arr[i].sec.second = 1;
                    arr[i].las.first = a[i][2], arr[i].las.second = 2;
                }
                else{
                    arr[i].fir.first = a[i][1], arr[i].fir.second = 1;
                    arr[i].sec.first = a[i][3], arr[i].sec.second = 3;
                    arr[i].las.first = a[i][2], arr[i].las.second = 2;
                }
            }
            else{//a[i][2] > a[i][1]
                if(a[i][1] >= a[i][3]){
                    arr[i].fir.first = a[i][2], arr[i].fir.second = 2;
                    arr[i].sec.first = a[i][1], arr[i].sec.second = 1;
                    arr[i].las.first = a[i][3], arr[i].las.second = 3;
                }
                else if(a[i][3] > a[i][2]){
                    arr[i].fir.first = a[i][3], arr[i].fir.second = 3;
                    arr[i].sec.first = a[i][2], arr[i].sec.second = 2;
                    arr[i].las.first = a[i][1], arr[i].las.second = 1;
                }
                else{
                    arr[i].fir.first = a[i][2], arr[i].fir.second = 2;
                    arr[i].sec.first = a[i][3], arr[i].sec.second = 3;
                    arr[i].las.first = a[i][1], arr[i].las.second = 1;
                }
            }

        }
        for(int i = 1; i <= n; i++){
            pii pos = arr[i].fir;
            ppl[pos.second][++cnt[pos.second]] = i;
            sum[pos.second] += pos.first;
        }
        while(cnt[1] > limit ||cnt[2] > limit || cnt[3] > limit){

            if(cnt[1] > limit){
                    if(flag[2] == 1){
                    flag[1] = 1;
                    while(cnt[1] > limit){
                        int minn = ppl[1][1], mini=1;
                        for(int i = 2; i < cnt[1]; i++)
                            if(cmp(ppl[1][i], minn)) minn = ppl[1][i], mini = i;
                        swap(ppl[1][cnt[1]], ppl[1][mini]);
                        cnt[1]--;
                        if(arr[minn].phase == 0){
                            arr[minn].phase = 1;
                        sum[arr[minn].fir.second] -= arr[minn].fir.first;
                        pii pos = arr[minn].sec;
                        ppl[3][++cnt[3]] = mini;
                        if(arr[minn].sec.second == 3)
                            sum[3] += arr[minn].sec.first;
                        else if(arr[minn].las.second == 3)
                            sum[3] += arr[minn].las.first;
                        }
                        else{
                            sum[arr[minn].sec.second] -= arr[minn].sec.first;
                            ppl[3][++cnt[3]] = mini;
                            if(arr[minn].sec.second == 3)
                            sum[3] += arr[minn].sec.first;
                            else if(arr[minn].las.second == 3)
                            sum[3] += arr[minn].las.first;
                        }
                        }
                    }
                else if(flag[3] == 1){
                    flag[1] = 1;
                    while(cnt[1] > limit){
                        int minn = ppl[1][1], mini=1;
                        for(int i = 2; i < cnt[1]; i++)
                            if(cmp(ppl[1][i], minn)) minn = ppl[1][i], mini = i;
                        swap(ppl[1][cnt[1]], ppl[1][mini]);
                        cnt[1]--;
                        if(arr[minn].phase == 0){
                                arr[minn].phase = 1;
                        sum[arr[minn].fir.second] -= arr[minn].fir.first;
                        pii pos = arr[minn].sec;
                        ppl[2][++cnt[2]] = mini;
                        if(arr[minn].sec.second == 2)
                            sum[2] += arr[minn].sec.first;
                        else if(arr[minn].las.second == 2)
                            sum[2] += arr[minn].las.first;
                        else
                            sum[2] += arr[minn].fir.first;
                        }
                        else{
                            sum[arr[minn].sec.second] -= arr[minn].sec.first;
                            ppl[2][++cnt[2]] = mini;
                        if(arr[minn].sec.second == 2)
                            sum[2] += arr[minn].sec.first;
                        else if(arr[minn].las.second == 2)
                            sum[2] += arr[minn].las.first;
                        }

                        }
                    }
                else{
                flag[1] = 1;
                while(cnt[1] > limit){
                    int minn = ppl[1][1], mini=1;
                    for(int i = 2; i < cnt[1]; i++)
                        if(cmp(ppl[1][i], minn)) minn = ppl[1][i], mini = i;
                    swap(ppl[1][cnt[1]], ppl[1][mini]);
                    cnt[1]--;
                    if(arr[minn].phase == 0){
                            arr[minn].phase = 1;
                    sum[arr[minn].fir.second] -= arr[minn].fir.first;
                    pii pos = arr[minn].sec;
                    ppl[pos.second][++cnt[pos.second]] = mini;
                    sum[pos.second] += pos.first;
                    }
                    else{
                        sum[arr[minn].sec.second] -= arr[minn].sec.first;
                        pii pos = arr[minn].las;
                        ppl[pos.second][++cnt[pos.second]] = mini;
                        sum[pos.second] += pos.first;
                    }
                }
                }
            }
            if(cnt[2] > limit){
                if(flag[1] == 1){
                    flag[2] = 1;
                    while(cnt[2] > limit){
                        int minn = ppl[2][1], mini=1;
                        for(int i = 2; i < cnt[2]; i++)
                            if(cmp(ppl[2][i], minn)) minn = ppl[2][i], mini = i;
                        swap(ppl[2][cnt[2]], ppl[2][mini]);
                        cnt[2]--;
                        if(arr[minn].phase == 0){
                                arr[minn].phase = 1;
                        sum[arr[minn].fir.second] -= arr[minn].fir.first;
                        ppl[3][++cnt[3]] = mini;
                        if(arr[minn].sec.second == 3)
                            sum[3] += arr[minn].sec.first;
                        else if(arr[minn].las.second == 3)
                            sum[3] += arr[minn].las.first;
                        }
                        else{
                        sum[arr[minn].sec.second] -= arr[minn].sec.first;
                        ppl[3][++cnt[3]] = mini;
                        if(arr[minn].sec.second == 3)
                            sum[3] += arr[minn].sec.first;
                        else if(arr[minn].las.second == 3)
                            sum[3] += arr[minn].las.first;
                        }
                        }
                    }
                else if(flag[3] == 1){
                    flag[2] = 1;
                    while(cnt[2] > limit){
                        int minn = ppl[2][1], mini=1;
                        for(int i = 2; i < cnt[2]; i++)
                            if(cmp(ppl[2][i], minn)) minn = ppl[2][i], mini = i;
                        swap(ppl[2][cnt[2]], ppl[2][mini]);
                        cnt[2]--;
                        if(arr[minn].phase == 0){
                            arr[minn].phase = 1;
                        sum[arr[minn].fir.second] -= arr[minn].fir.first;
                        pii pos = arr[minn].sec;
                        ppl[1][++cnt[1]] = mini;
                        if(arr[minn].sec.second == 1)
                            sum[1] += arr[minn].sec.first;
                        else if(arr[minn].las.second == 1)
                            sum[1] += arr[minn].las.first;
                        }
                        else{
                            sum[arr[minn].sec.second] -= arr[minn].sec.first;
                        ppl[1][++cnt[1]] = mini;
                        if(arr[minn].sec.second == 1)
                            sum[1] += arr[minn].sec.first;
                        else if(arr[minn].las.second == 1)
                            sum[1] += arr[minn].las.first;
                        }
                    }
                }
                else{
                    flag[2] = 1;
                    while(cnt[2] > limit){
                        int minn = ppl[2][1], mini=1;
                        for(int i = 2; i < cnt[2]; i++)
                            if(cmp(ppl[2][i], minn)) minn = ppl[2][i], mini = i;
                        swap(ppl[2][cnt[2]], ppl[2][mini]);
                        cnt[2]--;
                        if(arr[minn].phase == 0){
                                arr[minn].phase = 1;
                            sum[arr[minn].fir.second] -= arr[minn].fir.first;
                            pii pos = arr[minn].sec;
                            ppl[pos.second][++cnt[pos.second]] = mini;
                            sum[pos.second] += pos.first;
                        }
                        else{
                            sum[arr[minn].sec.second] -= arr[minn].sec.first;
                            pii pos = arr[minn].las;
                            ppl[pos.second][++cnt[pos.second]] = mini;
                            sum[pos.second] += pos.first;
                        }
                    }
                }
            }
            if(cnt[3] > limit){
                if(flag[1] == 1){
                    flag[3] = 1;
                    while(cnt[3] > limit){
                        int minn = ppl[3][1], mini=1;
                        for(int i = 3; i < cnt[3]; i++)
                            if(cmp(ppl[3][i], minn)) minn = ppl[3][i], mini = i;
                        swap(ppl[3][cnt[3]], ppl[3][mini]);
                        cnt[3]--;
                        if(arr[minn].phase == 0){
                                arr[minn].phase = 1;
                        sum[arr[minn].fir.second] -= arr[minn].fir.first;
                        ppl[2][++cnt[2]] = mini;
                        if(arr[minn].sec.second == 2)
                            sum[2] += arr[minn].sec.first;
                        else if(arr[minn].las.second == 2)
                            sum[2] += arr[minn].las.first;
                        else
                            sum[2] += arr[minn].fir.first;
                        }
                        else{
                            sum[arr[minn].sec.second] -= arr[minn].sec.first;
                        ppl[2][++cnt[2]] = mini;
                        if(arr[minn].sec.second == 2)
                            sum[2] += arr[minn].sec.first;
                        else if(arr[minn].las.second == 2)
                            sum[2] += arr[minn].las.first;
                        }
                        }
                    }
                else if(flag[2] == 1){
                    flag[3] = 1;
                    while(cnt[3] > limit){
                        int minn = ppl[3][1], mini=1;
                        for(int i = 3; i < cnt[3]; i++)
                            if(cmp(ppl[3][i], minn)) minn = ppl[3][i], mini = i;
                        swap(ppl[3][cnt[3]], ppl[3][mini]);
                        cnt[3]--;
                        if(arr[minn].phase == 0){
                            arr[minn].phase = 1;
                        sum[arr[minn].fir.second] -= arr[minn].fir.first;
                        ppl[1][++cnt[1]] = mini;
                        if(arr[minn].sec.second == 1)
                            sum[1] += arr[minn].sec.first;
                        else if(arr[minn].las.second == 1)
                            sum[1] += arr[minn].las.first;
                        }
                        else{
                            sum[arr[minn].sec.second] -= arr[minn].sec.first;
                        ppl[1][++cnt[1]] = mini;
                        if(arr[minn].sec.second == 1)
                            sum[1] += arr[minn].sec.first;
                        else if(arr[minn].las.second == 1)
                            sum[1] += arr[minn].las.first;
                        }
                    }
                }
                else{
                    flag[3] = 1;
                    while(cnt[3] > limit){
                        int minn = ppl[3][1], mini=1;
                        for(int i = 2; i < cnt[3]; i++)
                            if(cmp(ppl[3][i], minn)) minn = ppl[2][i], mini = i;
                        swap(ppl[3][cnt[3]], ppl[3][mini]);
                        cnt[3]--;
                        if(arr[minn].phase == 0){
                            arr[minn].phase = 1;
                        sum[arr[minn].fir.second] -= arr[minn].fir.first;
                        pii pos = arr[minn].sec;
                        ppl[pos.second][++cnt[pos.second]] = mini;
                        sum[pos.second] += pos.first;
                        }
                        else{
                            sum[arr[minn].sec.second] -= arr[minn].sec.first;
                            pii pos = arr[minn].las;
                            ppl[pos.second][++cnt[pos.second]] = mini;
                            sum[pos.second] += pos.first;
                        }
                    }
                }
            }
        }
        for(int i = 1; i <= 3;i++)
            ans += sum[i];
        cout<< ans << "\n";
    }
    return 0;
}
