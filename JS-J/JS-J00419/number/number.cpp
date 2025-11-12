#include <iostream>
#include <queue>
using namespace std;

string s;
priority_queue<int> q;
void init(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    return;
}

void solve(){
    for(int i = 0; i < s.size(); ++ i){
        if(s[i] >= '0' && s[i] <= '9')
            q.push(s[i] - '0');
    }
    bool first = true;
    while(!q.empty()){
        int n = q.top();
        if(first){
            if(n == 0){
                cout << 0;
                break;
            }else{
                first = false;
            }
        }
        cout << n;
        q.pop();
    }
    cout << endl;
    return;
}

void close(){
    fclose(stdin);
    fclose(stdout);
    return;
}

int main(){
    init();
    solve();
    close();
    return 0;
}
