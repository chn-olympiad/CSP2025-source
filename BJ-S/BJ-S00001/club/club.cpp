#include<bits/stdc++.h>
using namespace std;
int cnta, cntb, cntc;
int ans;
int max_possible;
bool can_contin=true;
struct student{
    int club1, club2, club3;
};
student a[1000005];
bool cmp(student x, student y){
    if(x.club1!=y.club1)return x.club1>y.club1;
    else if(x.club2!=y.club2)return x.club2>y.club2;
    else return x.club3>y.club3;
}
void dfs(int sum, int depth, int n){
    if(depth>n){
        ans = max(ans, sum);
        if(ans==max_possible){
            can_contin = false;
        }
        return;
    }
    if(can_contin){
        dfs(sum, depth+1, n);
        if(cnta<n/2){
            cnta++;
            dfs(sum+a[depth].club1, depth+1, n);
            cnta--;
        }
        if(cntb<n/2){
            cntb++;
            dfs(sum+a[depth].club2, depth+1, n);
            cntb--;
        }
        if(cntc<n/2){
            cntc++;
            dfs(sum+a[depth].club3, depth+1, n);
            cntc--;
        }
    }
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        ans=0;
        int n;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i].club1 >> a[i].club2 >> a[i].club3;
        }
        cnta=0;
        cntb=0;
        cntc=0;
        can_contin=true;
        max_possible=0;
        for(int i=1; i<=n; i++){
            max_possible+=max(a[i].club1, max(a[i].club2, a[i].club3));
        }
        sort(a+1, a+n+1, cmp);
        dfs(0, 1, n);
        cout << ans << endl;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}