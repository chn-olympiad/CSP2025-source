#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

std::map<string, string> dict;//string i -> j
std::vector<string> st;//going to be matched
std::vector<int> addn;
int n;
int ans;

bool cmp(string a, string b);
bool finds(string a, string b);
void diff(string& match, string& delta,string s1, string s2);

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin>>n>>q;
    string s1, s2;
    for(int i = 1;i<=n;i++){

        cin>>s1>>s2;
        dict[s1] = s2;
        st.push_back(s1);
    }
    //find the same string
    sort(st.begin(),st.end(),cmp);
    addn.reserve(200005);
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            if(finds(st[j], st[i])) addn[i]++;
        }
    }
    while(q--){
        ans = 0;
        cin>>s1>>s2;
        string delta,match;
        diff(match,delta,s1,s2);
        for(int i = 0;i<n;i++){
            if(st[i] == match){
                if(dict[match] == delta) ans+= addn[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

bool cmp(string a,string b){
    int l = a.length();
    if(l != b.length()) return a.length() < b.length();
    for(int i = 0;i<l;i++){
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

bool finds(string a, string b){
    //find that if b is included in a
    int l = b.length();
    int cnt = 0;
    for(int i = 0;i<a.length();i++){
        if(a[i] == b[cnt]){
            cnt++;
            if(cnt == l) return true;
        }
        else{
            cnt = 0;
            if(a[i] == b[cnt]){
                cnt++;
            }
        }
    }
    return false;
}

void diff(string& match, string& delta, string s1, string s2){
    bool flag = s1.length()<s2.length();
    for(int i = 0;i<std::min(s1.length(), s2.length());i++){
        if(s1[i] != s2[i]){
            match = match + s1[i];
            delta = delta + s2[i];
        }
    }
    if(flag){
        for(int i = s1.length();i<s2.length();i++){
            delta = delta + s2[i];
        }
    }
    else{
        for(int i = s2.length();i<s1.length();i++){
            match = match + s1[i];
        }
    }
}
