#include <iostream>

using namespace std;

int n, m;

char issimple[514];

int naixin[514];

bool selected[514];

int cur_mans;

int p = 0;

const int MOD = 998244353;

void dfs(int depth){
    if(depth != n){
        for(int x = 0; x < n; x++){
            // cout << "(" << depth << ")[" << x << "] :" "selected = " << selected[x] << 
            // ", naixin = " << naixin[x] << "(>" << depth - cur_mans<<")" << endl;
            if(selected[x]) continue;

            // Selected!
            if(issimple[depth]=='1' && naixin[x] > depth - cur_mans) cur_mans++;
            selected[x]=true;
            // cout << "Call\n";
            dfs(depth+1);
            // cout << "Call off\n";
            selected[x]=false;
            if(issimple[depth]=='1' && naixin[x] > depth - cur_mans) cur_mans--;
        }
    }else{
        // cout << "cur_mans: " << cur_mans << endl;
        if(cur_mans >= m){
            p++;
            if(p==MOD) p=0;
        }
    }
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m;

    cin >> issimple;

    for(int i = 0; i < n; i++){
        cin >> naixin[i];
    }

    // cout << "Start to DFS\n";

    dfs(0);

    cout << p << endl;
    
    return 0;
}