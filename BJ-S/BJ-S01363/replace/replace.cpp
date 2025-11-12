#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

string s1[N], s2[N];

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
    while(q--){
        string a, b;
        cin >> a >> b;
        if(a.size() != b.size()){
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        for(int i = 0; i < a.size(); i++){
            for(int j = i; j < a.size(); j++){
				string tmp1 = "", tmp2 = "";
                for(int k = i; k <= j; k++){
                    tmp1 += a[k]; tmp2 += b[k];
				}
				bool flag = 0;
				for(int k = 0; k < i; k++){
					 if(a[k] != b[k]){
						 flag = 1;
					 }
				}
				for(int k = j + 1; k < a.size(); k++){
					 if(a[k] != b[k]){
						 flag = 1;
					 }
				}
				if(flag) continue;
                for(int k = 1; k <= n; k++){
                    if(s1[k] == tmp1 && s2[k] == tmp2){
					    ans++; //cout << i << " " << j << endl;
				    }
                }
            }
            
        }
        cout << ans << endl;
    }
}
