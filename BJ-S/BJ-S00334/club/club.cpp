#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct student{
    int la,lb,lc;
};
int n;
long long ans;
vector <student> x;
vector <student> a,b,c;
bool cmp1(student x,student y){
    return x.la > y.la;
}
bool cmp2(student x,student y){
    return x.lb > y.lb;
}
bool cmp3(student x,student y){
    return x.lc > y.lc;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        a.clear();
        b.clear();
        c.clear();
        ans = 0;
        cin >> n;
        x.clear();
        bool spa = true,spb = true;
        for(int i = 1;i <= n;i++){
            student op;
            cin >> op.la >> op.lb >> op.lc;
            if(op.lb != 0 || op.lc != 0){
                spa = false;
            }
            if(op.lc != 0){
                spb = false;
            }
            x.push_back(op);
        }
        if(spa){
            sort(x.begin(),x.end(),cmp1);
            for(int i = 0;i < n / 2;i++){
                ans += x[i].la;
            }
            cout << ans << endl;
            continue;
        }
        if(n == 2){
            int pa = x[0].la + x[1].lb;
            int pb = x[0].la + x[1].lc;
            int pc = x[0].lb + x[1].lc;
            int pd = x[0].lb + x[1].la;
            int pe = x[0].lc + x[1].la;
            int pf = x[0].lc + x[1].lb;
            cout << max(max(max(pa,pb),max(pc,pd)),max(pe,pf));
            continue;
        }
        while(!x.empty()){
            sort(a.begin(),a.end(),cmp1);
            sort(b.begin(),b.end(),cmp2);
            sort(c.begin(),c.end(),cmp3);
            student k = x[0];
            int od[4];
            if(k.la > k.lb){
                if(k.la >= k.lc){
                    od[1] = 1;
                    od[2] = 3;
                    od[3] = 2;
                }
                else if(k.la < k.lc){
                    od[1] = 3;
                    od[2] = 1;
                    od[3] = 2;
                }
            }
            if(k.lb > k.la){
                if(k.lb >= k.lc){
                    od[1] = 2;
                    od[2] = 3;
                    od[3] = 1;
                }
                else if(k.lb < k.lc){
                    od[1] = 3;
                    od[2] = 2;
                    od[3] = 1;
                }
            }
            if(od[1] == 1){
                if((int)a.size() <= n / 2){
                    a.push_back(k);
                    x.erase(x.begin());
                    continue;
                }
                if(a[0].la < k.la){
                    x.push_back(a[0]);
                    a.push_back(k);
                    a.erase(a.begin());
                    continue;
                }
            }
            else if(od[1] == 2){
                if((int)b.size() <= n / 2){
                    b.push_back(k);
                    x.erase(x.begin());
                    continue;
                }
                if(b[0].lb < k.lb){
                    x.push_back(b[0]);
                    b.push_back(k);
                    b.erase(b.begin());
                    continue;
                }
            }
            else if(od[1] == 3){
                if((int)c.size() <= n / 2){
                    c.push_back(k);
                    x.erase(x.begin());
                    continue;
                }
                if(c[0].lc < k.lc){
                    x.push_back(c[0]);
                    c.push_back(k);
                    c.erase(c.begin());
                    continue;
                }
            }
            if(od[2] == 1){
                if((int)a.size() <= n / 2){
                    a.push_back(k);
                    x.erase(x.begin());
                    continue;
                }
                if(a[0].la < k.la){
                    x.push_back(a[0]);
                    a.push_back(k);
                    a.erase(a.begin());
                    continue;
                }
            }
            else if(od[2] == 2){
                if((int)b.size() <= n / 2){
                    b.push_back(k);
                    x.erase(x.begin());
                    continue;
                }
                if(b[0].lb < k.lb){
                    x.push_back(b[0]);
                    b.push_back(k);
                    b.erase(b.begin());
                    continue;
                }
            }
            else if(od[2] == 3){
                if((int)c.size() <= n / 2){
                    c.push_back(k);
                    x.erase(x.begin());
                    continue;
                }
                if(c[0].lc < k.lc){
                    x.push_back(c[0]);
                    c.push_back(k);
                    c.erase(c.begin());
                    continue;
                }
            }
            if(od[3] == 1){
                if((int)a.size() <= n / 2){
                    a.push_back(k);
                    x.erase(x.begin());
                    continue;
                }
                if(a[0].la < k.la){
                    x.push_back(a[0]);
                    a.push_back(k);
                    a.erase(a.begin());
                    continue;
                }
            }
            else if(od[3] == 2){
                if((int)b.size() <= n / 2){
                    b.push_back(k);
                    x.erase(x.begin());
                    continue;
                }
                if(b[0].lb < k.lb){
                    x.push_back(b[0]);
                    b.push_back(k);
                    b.erase(b.begin());
                    continue;
                }
            }
            else if(od[3] == 3){
                if((int)c.size() <= n / 2){
                    c.push_back(k);
                    x.erase(x.begin());
                    continue;
                }
                if(c[0].lc < k.lc){
                    x.push_back(c[0]);
                    c.push_back(k);
                    c.erase(c.begin());
                    continue;
                }
            }
        }
        /*
        for(auto i:a){
            cout << i.la << " ";
        }
        cout << endl << endl;
        for(auto i:b){
            cout << i.lb << " ";
        }
        cout << endl << endl;
        for(auto i:c){
            cout << i.lc << " ";
        }
        cout << endl << endl;
        */
        for(int i = 0;i < (int)a.size();i++){
            ans += a[i].la;
        }
        for(int i = 0;i < (int)b.size();i++){
            ans += b[i].lb;
        }
        for(int i = 0;i < (int)c.size();i++){
            ans += c[i].lc;
        }
        cout << ans << endl;
    }
    return 0;
}
