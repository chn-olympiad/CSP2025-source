#incldue <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, q;
string a[N][3];

int main(){

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for(int i = 1;i <= n;i ++){
        cin >> a[i][1] >> a[i][2];
    }

    while(q --){
        string s1, s2;

        cin >> s1 >> s2;

        int x;
        for(int i = 0;i <= int(s1.size())-1;i ++){
            if(s1[i] == 'b'){
                x = i;
                break;
            }
        }

        int y;
        for(int j = 0;j <= int(s2.size())-1;j ++){
            if(s2[i] == 'b'){
                y = i;
                break;
            }
        }

        int cnt = 0;

        for(int i = 1;i <= n;i ++){
            int xx, yy;
            for(int j = 0;j <= int(a[i][1].size())-1;j ++){
                if(a[i][1][j] == 'b'){
                    xx = j;
                    break;
                }
            }
            for(int j = 0;j <= int(a[i][2].size())-1;j ++){
                if(a[i][2][j] == 'b'){
                    yy = j;
                    break;
                }
            }
            if(xx <= x && a[i][1].size() <= s1.size()){
                if(yy == y && a[i][2].size() <= s2.size()){
                    cnt ++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}