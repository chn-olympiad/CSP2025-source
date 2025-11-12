# include <bits/stdc++.h>
using namespace std;
# define int long long
int n,ans;
int f[55][55][55][55];
struct node{                            // 记每一个人
    int a,b,c;
} a[100005];
struct p1{
    int num,id;
} ;
vector <p1> pe[5];
bool cmp1(p1 x,p1 y){
    return x.num > y.num;
}

bool cmpa(node a,node b){
    return a.a > b.a;
}
bool cmpb(node a,node b){
    return a.b > b.b;
}
bool cmpc(node a,node b){
    return a.c > b.c;
}
bool cmpint(int a,int b){
    return a > b;
}


void dfs(int step,int ca,int cb,int cc,int tot){
    if (ca > n/2 || cb > n/2 || cc > n/2){
        return ;
    }
    //cout << step << ' ' << ca << ' ' << cb << ' ' << cc << ' ' << tot << endl;
    if (step > n){
        ans = max(ans,tot);
        return ;
    }
    dfs(step+1,ca+1,cb,cc,tot+a[step].a);
    dfs(step+1,ca,cb+1,cc,tot+a[step].b);
    dfs(step+1,ca,cb,cc+1,tot+a[step].c);
}


void MAIN(){
    cin >> n;
    for (int i=1;i<=3;i++){
        pe[i].clear();
    }
    for (int i=1;i<=n;i++){
        cin >> a[i].a >> a[i].b >> a[i].c;
        if (a[i].a > a[i].b && a[i].a > a[i].c){
            pe[1].push_back({a[i].a,i});
        }
        if (a[i].b > a[i].c && a[i].b > a[i].a){
            pe[2].push_back({a[i].b,i});

        }
        if (a[i].c > a[i].b && a[i].c > a[i].a){
            pe[3].push_back({a[i].c,i});
        }
    }

    bool isa = 1;
    for (int i=1;i<=n;i++){
        if (a[i].b != 0 || a[i].c != 0) isa = 0;
    }

    if (isa){
        sort(a+1,a+n+1,cmpa);
        int aannss = 0;
        for (int i=1;i<=n/2;i++){
            aannss += a[i].a;
        }
        cout << aannss << endl;
        return ;
    }

    if (n <= 20){
        ans = -1;
        dfs(1,0,0,0,0);
        cout << ans << endl;
        return ;
    }




    if (n <= 50){
        memset(f,0,sizeof f);
        f[1][1][0][0] = a[1].a;
        f[1][0][1][0] = a[1].b;
        f[1][0][0][1] = a[1].c;
        for (int i=2;i<=n;i++){
            for (int l1=0;l1<=i/2;l1++){
                for (int l2=0;l2<=i/2;l2++){
                    int l3 = i - l1 - l2;
                    if (l3 > i/2) continue ;
                    if (l1 > 0){
                        f[i][l1][l2][l3] = max(f[i][l1][l2][l3], f[i-1][l1-1][l2][l3] + a[i].a);
                    }
                    if (l2 > 0){
                        f[i][l1][l2][l3] = max(f[i][l1][l2][l3], f[i-1][l1][l2-1][l3] + a[i].b);
                    }
                    if (l3 > 0){
                        f[i][l1][l2][l3] = max(f[i][l1][l2][l3], f[i-1][l1][l2][l3-1] + a[i].c);
                    }
                }
            }
        }

        int mx = 0;

        for (int l1=0;l1<=n/2;l1++){

            for (int l2=0;l2<=n/2;l2++){

                int l3 = n - l1 - l2;

                if (l3 > n/2) continue ;

                if (f[n][l1][l2][l3] > mx){
                    mx = max(f[n][l1][l2][l3],mx);
                    //cout << l1 << ' ' << l2 << ' ' << l3 << endl;
                }

            }
        }
        //cout << f[1][1][0][0] << ' ' << f[2][1][0][1] << ' ' << f[3][2][0][1] << ' ' << f[4][2][1][1] << endl;
        cout << mx << endl;
        return ;
    }



    ans = 0;
    sort(pe[1].begin(),pe[1].end(),cmp1);
    sort(pe[2].begin(),pe[2].end(),cmp1);
    sort(pe[3].begin(),pe[3].end(),cmp1);
    vector <int> tmp;
    for (int i=0;i<min((int)(pe[1].size()),n/2);i++){
        ans += pe[1][i].num;
    }
    for (int i=n/2;i<pe[1].size();i++){
        tmp.push_back(pe[1][i].id);
    }

    for (int i=0;i<min((int)(pe[2].size()),n/2);i++){
        ans += pe[2][i].num;
    }
    for (int i=n/2;i<pe[2].size();i++){
        tmp.push_back(pe[2][i].id);
    }

    for (int i=0;i<min((int)(pe[3].size()),n/2);i++){
        ans += pe[3][i].num;
    }
    for (int i=n/2;i<pe[3].size();i++){
        tmp.push_back(pe[3][i].id);
    }

    for (int i=0;i<tmp.size();i++){
        node x = a[tmp[i]];
        int mn = min(min(x.a,x.b),x.c);
        int mx = max(max(x.a,x.b),x.c);
        ans += (x.a + x.b + x.c) - mn - mx;
    }

    cout << ans << endl;
}




signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while (t--){
        MAIN();
    }
}
