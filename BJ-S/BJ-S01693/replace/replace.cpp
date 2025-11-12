# include <bits/stdc++.h>
using namespace std;
int n,q;
struct node{
    string a,b;
} a[100005];


int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> a[i].a >> a[i].b;
    }

    while (q--){
        int cnt = 0;
        string t1,t2;
        cin >> t1 >> t2;
        for (int i=1;i<=n;i++){                     // 用哪种替换方式
            int len = a[i].a.size();
            string tmp = t1.substr(0,len);
            if (tmp == a[i].a){
                string t11 = t1;
                for (int j=0;j<len;j++){
                    t11[j] = a[i].b[j];
                }
                if (t11 == t2){
                    cnt++;
                    continue ;
                }
            }
            //cout << i << ' ' << tmp << "\n";
            int j;
            for (j=len;j<t1.size();j++){
                tmp = tmp.substr(1) + t1[j];
                //cout << tmp << ' ';
                if (tmp == a[i].a){
                    string t11 = t1;
                    for (int k=0;k<len;k++){
                        t11[k+j-len+1] = a[i].b[k];
                    }
                    if (t11 == t2){
                        cnt++;
                        continue ;
                    }
                }
            }
            //cout << endl;
        }

        cout << cnt << endl;
    }
}
