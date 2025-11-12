#include<iostream>
#include<string>
#include<vector>
using namespace std;

int mx(int a,int b){
    return a<b?b:a;
}
int mn(int a,int b){
    return a<b?a:b;
}

void replace(string& s,string t,int pos){
    for(int i = pos; i < pos+t.size()-1; i++){
        s[i] = t[i-pos];
    }
}

int n,q;
string s[2005][2];
int nxt[1005][2005];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> s[i][0] >> s[i][1];
    }
    for(int k = 1; k <= n; k++){
        string b = "#"+s[k][0];
        int lb = b.size()-1,j = 0;
        for(int i = 2; i < lb; i++){
            while(j && b[i]!=b[j+1]){
                j = nxt[k][j];
            }
            if(b[i] == b[j+1]){
                j++;
            }
            nxt[k][i] = j;
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 0; i <= s[k][0].size(); i++){
            //cout << nxt[k][i] << " ";
        }//cout << endl << s[k][0] << endl;
    }

    while(q--){
        int ans = 0;
        string a,c;
        cin >> a >> c;
        a = "#"+a;
        for(int k = 1; k <= n; k++){
            vector<int> pos;
            int j = 0;
            string b = "#"+s[k][0];
            int lb = b.size()-1,la = a.size()-1;
            for(int i = 1; i <= la; i++){
                while(j && a[i]!=b[j+1]){
                    j = nxt[k][j];
                }
                if(a[i] == b[j+1]){
                    j++;
                }
                if(j == lb){
                    pos.push_back(i-lb+1);
                    j = nxt[k][j];
                }
            }

            for(int i = 0; i < pos.size(); i++){
                //cout << pos[i] << " ";
                replace(a,s[k][1],pos[i]);
                //cout << a << endl;
                if(a == "#"+c){
                    ans++;
                }
                replace(a,s[k][0],pos[i]);
            }
        }//cout << endl;
        cout << ans << endl;
    }
    /*
    string a = "#ababababcabab",b = "#bab";
    int j = 0;
    int lb = b.size()-1,la = a.size()-1;
    for(int i = 2; i <= lb; i++){
        while(j && b[i]!=b[j+1]){
            j = nxt[j];
        }
        if(b[i] == b[j+1]){
            j++;
        }
        nxt[i] = j;
    }

    j = 0;
    for(int i = 1; i <= la; i++){
        while(j && a[i]!=b[j+1]){
            j = nxt[j];
        }
        if(a[i] == b[j+1]){
            j++;
        }
        if(j == lb){
            cout << i-lb+1 << endl;
            j = nxt[j];
        }
    }
    */
    return 0;
}
