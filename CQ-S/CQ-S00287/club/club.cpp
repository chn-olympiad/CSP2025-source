#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
int a[100005][4];

// #define chose(int x) chose##x

struct node { 
    int nowchose;
    // vector<int> score;
    int chose1, chose2, chose3;
    int distonxt;
    int score1, score2, score3;
    bool operator <(node A) const {
        return distonxt > A.distonxt;
    }
    bool operator == (node A) const {
		return chose1 == A.chose1 && chose2==A.chose2 && chose3 == A.chose3 && distonxt == A.distonxt && score1 == A.score1 && score2 == A.score2 && score3 == A.score3;
	} 

};
vector<node> chose[4];

int getchose(node u, int need) {
    if ( need == 1) {
        return u.chose1;
    } else if ( need == 2 ) {
        return u.chose2;
    } else if ( need == 3 ) {
        return u.chose3;
    }
}
bool cmp4(vector<node> a, vector<node> b ) {
    return a.size() >= b.size();
}
int getscore(node u, int need ) {
    if ( need == 1){ 
        return u.score1;
    } else if ( need == 2 ) {
        return u.score2;
    } else if ( need == 3 ) {
        return u.score3;
    }
}
void addinto(node u, int need ) {
    if ( need == 1 ) {
        chose[1].push_back(u);
    } else if ( need == 2 ) {
        chose[2].push_back(u);
    } else if ( need == 3 ) {
        chose[3].push_back(u);
    }
}

bool cmp1(node a, node b){
    return a.score1 > b.score1;
}

bool cmp2(node a, node b){
    return a.score2 > b.score2;
}

bool cmp3(node a, node b){
    return a.score3 > b.score3;
} 
int mp[5];
int choice[100005];
int ans;
void dfs(int u) {
	if ( u == n + 1) {
		memset(mp, 0, sizeof mp);
		for ( int i = 1 ; i <= n ; i ++ ) {
			mp[choice[i]] ++;
		}
		if ( mp[1] > n / 2 || mp[2] > n/2 || mp[3] > n/2) {
			return;
		}
		int sum = 0;
		for ( int i = 1 ; i <= n ; i ++ ) {
			sum += a[i][choice[i]];
		}
		ans = max(ans, sum);
		return;
	}
	choice[u] = 1;
	dfs(u + 1);
	choice[u] = 2;
	dfs(u + 1);
	choice[u] = 3;
	dfs(u + 1);
}

void work() {/*
	memset(mp, 0, sizeof mp);
    chose[1].clear();
    chose[2].clear();
    chose[3].clear();*/
    cin >> n;
    int tmp = 0;
    vector<int> chose1;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
		tmp += a[i][2] + a[i][3];
		chose1.push_back(a[i][1]);
		/*
        if ( a[i][1] > a[i][2] && a[i][1] > a[i][3] ) {
            if ( a[i][2] > a[i][3] ) {
                chose[1].push_back(node{1, 1, 2, 3, a[i][1] - a[i][2], a[i][1], a[i][2], a[i][3]});
            } else {
                chose[1].push_back(node{1, 1, 3, 2, a[i][1] - a[i][3], a[i][1], a[i][2], a[i][3]});
            }
        } else if ( a[i][2] > a[i][1] && a[i][2] > a[i][3] ){
            if ( a[i][1] > a[i][3] ) {
                chose[2].push_back(node{1, 2, 1, 3, a[i][2] - a[i][1], a[i][1], a[i][2], a[i][3]});
            } else {
                chose[2].push_back(node{1, 2, 3, 1, a[i][2] - a[i][3], a[i][1], a[i][2], a[i][3]});
            }
        } else if ( a[i][3] > a[i][1] && a[i][3] > a[i][2] ){
            if ( a[i][1] > a[i][2] ) {
                chose[3].push_back(node{1, 3, 1, 2, a[i][3] - a[i][1], a[i][1], a[i][2], a[i][3]});
            } else {
                chose[3].push_back(node{1, 3, 2, 1, a[i][3] - a[i][2], a[i][1], a[i][2], a[i][3]});
            }
        } else if ( a[i][1] == a[i][2] ) {
            chose[1].push_back(node{1, 1, 2, 3, 0, a[i][1], a[i][2], a[i][3]});
        } else if ( a[i][2] == a[i][3] ) {
            chose[2].push_back(node{1, 2, 3, 1, 0, a[i][1], a[i][2], a[i][3]});
        } else if ( a[i][1] == a[i][3] ) {
            chose[3].push_back(node{1, 3, 1, 2, 0, a[i][1], a[i][2], a[i][3]});
        }*/
    }/*
    vector<node> chose2[5];
    sort(chose[1].begin(), chose[1].end(), cmp1);
    sort(chose[2].begin(), chose[2].end(), cmp2);
    sort(chose[3].begin(), chose[3].end(), cmp3);
    chose2[1] = chose[1];
    chose2[2] = chose[2];
    chose2[3] = chose[3];
    sort(chose + 1, chose + 4, cmp4);
    if (chose2[1] == chose[1]) {
        mp[1] = 1;
    } else if ( chose2[1] == chose[2] ) {
        mp[1] = 2;
    } else if ( chose2[1] == chose[3]){
        mp[1] = 3;
    }
    if (chose2[2] == chose[1]) {
        mp[2] = 1;
    } else if ( chose2[2] == chose[2] ) {
        mp[2] = 2;
    } else if ( chose2[2] == chose[2]){
        mp[2] = 3;
    }
    if (chose2[3] == chose[1]) {
        mp[3] = 1;
    } else if ( chose2[3] == chose[2] ) {
        mp[3] = 2;
    } else if ( chose2[3] == chose[3]){
        mp[3] = 3;
    }
    cout << "mp: " << mp[1] << " " << mp[2] << " " << mp[3] << endl;	
    cout << "start to output score list\n";
    for ( auto v : chose[1] ) {
        cout << getscore(v, mp[1]) << " " ;
    }
    cout << endl;
    for ( auto v : chose[2] ) {
        cout << getscore(v, mp[2]) << " " ;
    }
    cout << endl;
    for ( auto v : chose[3] ) {
        cout << getscore(v, mp[3]) << " " ;
    }
    cout << endl;
    // cout << "input ok." << endl;
    int ans = 0;
    priority_queue<node> q ;
    for ( int i = 1 ; i <= chose[1].size() ; i ++ ) {
        if ( i <= n / 2 ) {
            q.push(chose[1][i-1]);
        } else {
            node u = q.top();
            if ( u.distonxt < chose[1][i-1].distonxt ) {
                q.pop();
                u.nowchose ++;
                q.push(chose[1][i-1]);
                int x = (a[i][u.nowchose]);
                u.distonxt = getscore(u, getchose(u, x)) - getscore(u, getchose(u, a[i][u.nowchose+1]));
                addinto(u, mp[getchose(u, u.nowchose)]);
            } else {
                cout << "Add " << getscore(chose[1][i-1],getchose(chose[1][i-1], a[i][chose[1][i-1].nowchose])) << " into " << getchose(chose[1][i-1], chose[1][i-1].nowchose) << endl;
                chose[1][i-1].nowchose ++;
                chose[1][i-1].distonxt = getscore(chose[1][i-1],getchose(chose[1][i-1], a[i][chose[1][i-1].nowchose])) - getscore(chose[1][i-1],getchose(chose[1][i-1], a[i][chose[1][i-1].nowchose+1]));
                addinto(chose[1][i-1], mp[getchose(chose[1][i-1], chose[1][i-1].nowchose)]);
            }
        }
    }
    while ( !q.empty() ) {
        node u = q.top();
         cout << "ans add the " << getscore(u, mp[1]) << " with the chose " << u.nowchose << endl;
        ans += getscore(u, mp[1]);
        q.pop();
    }
    sort(chose[2].begin(), chose[2].end(), cmp2);
    sort(chose[3].begin(), chose[3].end(), cmp3);
    sort(chose + 2, chose + 4, cmp4);
    cout << "mp: " << mp[1] << " " << mp[2] << " " << mp[3] << endl;
    cout << "start to output score list\n";
    for ( auto v : chose[1] ) {
        cout << getscore(v, mp[1]) << " " ;
    }
    cout << endl;
    for ( auto v : chose[2] ) {
        cout << getscore(v, 2) << " " ;
    }
    cout << endl;
    for ( auto v : chose[3] ) {
        cout << getscore(v, 3) << " " ;
    }
    cout << endl;
    for ( int i = 1 ; i <= chose[2].size() ; i ++ ) {
        if ( i <= n / 2 ) {
            q.push(chose[2][i-1]);
            // cout << chose[2][i-1].score2 << "has been into it/." << endl;
        } else {
            node u = q.top();
            if ( u.distonxt < chose[2][i-1].distonxt ) {
                q.pop();
                u.nowchose ++;
                // cout << "Start kick\n";
                // cout << u.score2 << "has been kick it." << endl;
                q.push(chose[2][i-1]);
                int x = (a[i][u.nowchose]);
                u.distonxt = getscore(u, getchose(u, x)) - getscore(u, getchose(u, a[i][u.nowchose+1]));
                addinto(u, mp[getchose(u, u.nowchose)]);
            } else {
                cout << "Add " << getscore(chose[2][i-1],getchose(chose[2][i-1], a[i][chose[2][i-1].nowchose])) << " into " << mp[getchose(chose[2][i-1], chose[2][i-1].nowchose)] << endl;
                chose[2][i-1].nowchose ++;
                chose[2][i-1].distonxt = getscore(chose[2][i-1],getchose(chose[2][i-1], a[i][chose[2][i-1].nowchose])) - getscore(chose[2][i-1],getchose(chose[2][i-1], a[i][chose[2][i-1].nowchose+1]));
                addinto(chose[2][i-1], mp[getchose(chose[2][i-1], chose[2][i-1].nowchose)]);
            }
        }
    }
    while ( !q.empty() ) {
        node u = q.top();
         cout << "ans add the " << u.score2 << " with the chose " << u.nowchose << endl;
        ans += getscore(u, mp[2]);
        q.pop();
    }
    for ( int i = 1 ; i <= chose[3].size() ; i ++ ) {
        if ( i <= n / 2 ) {
            q.push(chose[3][i-1]);
        } else {
            node u = q.top();
            if ( u.distonxt < chose[3][i-1].distonxt ) {
                q.pop();
                q.push(chose[3][i-1]);
                u.nowchose ++;
                int x = (a[i][u.nowchose]);
                u.distonxt = getscore(u, mp[getchose(u, x)]) - getscore(u, mp[getchose(u, a[i][u.nowchose+1])]);
            }
        }
    }
    while ( !q.empty() ) {
        node u = q.top();
        // cout << "ans add the " << u.score3 << " with the chose " << u.nowchose << endl;
        ans += u.score3;
        ans += getscore(u, mp[3]);
        q.pop();
    }
    cout << ans << endl;*/
    if ( tmp == 0 ) {
    	sort(chose1.begin(), chose1.end(), greater<int>() );
    	for ( int i = 0 ; i < n / 2 ; i ++ ) {
    		ans += chose1[i];
		}
	}else if ( n <= 30 ) {
    	ans = 0;
    	dfs(1);
	}
    cout << ans << endl;
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
    cin >> T;
    while ( T -- ) {
//        cout << "on first round\n";
        work();
//        cout << " ----------------------------------------- ";
    }
}

//绑匪贪心？
