#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
vector<vector<int> > s;//s[i][j]: person i to club j satisfy
int n,maxans;
int num[3];//num[i]: number of person in club i
int maxnext[100005];
//int cnt;

void dfs(int d, int ans);
bool cmp(vector<int> a,vector<int> b);

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    int a;
    s.reserve(100005);
    while(t--){
        //cnt = 0;
        maxans = 0;
        num[0] = num[1] = num[2] = 0;
        memset(maxnext, -1, sizeof(maxnext));
        while(n--) s[n].clear();
        cin>>n;
        int maxa = -1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<3;j++){
                cin>>a;
                if(maxa < a) maxa = a;
                s[i].push_back(a);
            }
            maxnext[i] =  (i == 0) ? maxa : (maxa + maxnext[i - 1]);
        }
        sort(s.begin(),s.end(),cmp);
        dfs(0,0);
        //cout<<cnt<<endl;
        cout<<maxans<<endl;
    }
}

bool cmp(vector<int> a,vector<int> b){
    if(a[0] != b[0]) return a[0] > b[0];
    if(a[1] != b[1]) return a[1] > b[1];
    return a[2] > b[2];
}

void dfs(int d, int ans){
    //cnt++;
    //cout<<d<<" "<<ans<<endl;
    if(maxans >= ans + maxnext[d]) return;
    if(d == n){
        if(maxans < ans) maxans = ans;
        return;
    }
    for(int i = 0;i<3;i++){
        //person d choose to join club i
        if(num[i] < n/2){
            //accepted
            num[i]++;
            dfs(d+1, ans+s[d][i]);
            num[i]--;
        }
    }
}
