#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
#ifdef DEBUG
#define dbg(x) cout<<__LINE__<<": " << #x << "="<<x<<"\n"
#else
#define dbg(x)
#endif // DEBUG

struct MaxPoint {
    int person, bumen;
    MaxPoint(int p=-1, int b=-1):person(p),bumen(b) {}
};

bool cmp(vector<int> &x, vector<int>&y) {
    return x[1]<y[1];
}

MaxPoint maxPerson(vector<vector<int>> &a,const vector<int> &cannotUse) {
    MaxPoint res(0,0);
    int maxA = 0;
    int n = a.size()-1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=3; j++) {
            for(int k=0; k<cannotUse.size(); k++) {
                if(j==cannotUse[k]) {
                    goto jumpout;
                }
            }
            if(a[i][j] > maxA) {
                maxA = a[i][j];
                res.person = i;
                res.bumen = j;
            }
jumpout:
            ;
        }
    }
    return res;
}

int solve(int n, vector<vector<int>> &a) {
    vector<int> b(4); // num of peolpe for the BuMen
    vector<int> dp(n+1);
    for(int i=1; i<=n; i++) {
        int choose = -1;
        for(int j=1; j<=3; j++) {
            if(dp[i] <= dp[i-1]+a[i][j] && b[j] <= (n/2)) {
                choose = j;
                dp[i] = dp[i-1]+a[i][j];

            }
        }
        if(choose!=-1) {
            b[choose]++;
        }
    }
    return dp[n];
}

int solve1(int n, vector<vector<int>> &a) {
    vector<int> b(4); // num of peolpe for the BuMen
    vector<int> cannotuse;
    int res = 0;
    while(a.size()>1) {
        MaxPoint choose = maxPerson(a,cannotuse);
        b[choose.bumen]++;
        if(b[choose.bumen]>=(n/2)) {
            cannotuse.push_back(choose.bumen);
        }

        res+=a[choose.person][choose.bumen];
        dbg(choose.person);
        dbg(choose.bumen);
        dbg(res);
        a.erase(a.begin()+choose.person);

    }

    return res;
}


bool checkA(int n, vector<vector<int>> &a) {
    for(int i=1; i<=n; i++) {
        if((a[i][2]!=0) || a[i][3]!=0) {
            return false;
        }
    }
    return true;
}

int solveA(int n, vector<vector<int>> &a) {
    int res = 0;
    sort(a.begin(), a.end(), cmp);
    for(int i=1; i<=(n/2); i++) {
        res+=a[a.size()-i][1];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream cin("club.in");
    ofstream cout("club.out");

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int res = 0;
        vector<vector<int>> a(n+1, vector<int>(4));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=3; j++) {
                cin>>a[i][j];
            }
        }
        if(checkA(n,a)){
            res = solveA(n,a);
        }
        else{
            res = solve(n,a);
        }
        cout << res <<"\n";
    }
    return 0;
}
