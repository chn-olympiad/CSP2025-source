#include <bits/stdc++.h>

using namespace std;
int n,p;
struct AA{
    int z[30],u,r;

}tree[5000005];
int tot;
int fg[5000005];
string a[200005][2];
int f[5000005];
void bu(string x,int u1,int r1){
    int h = 0;
    for(int i = x.size()-1;i >= 0;i--){
        if(tree[h].z[x[i]-'a']){
            h = tree[h].z[x[i]-'a'];
        }else{
            tree[h].z[x[i]-'a'] = ++tot;
            h = tot;
        }
        //cout << x[i];
    }
    tree[h].u = u1;
    tree[h].r = r1;
    //cout << endl;
}
int cl(string x,string y,int rt){
    int h = 0;
    int ff = 0;
    for(int i = rt;i >= 0;i--){
        if(tree[h].z[x[i]-'a']){
            h = tree[h].z[x[i]-'a'];
        }else{
            return ff;
        }
        //cout << x[i];
        int flag = 0;
        int tot1 = 0;
        if(tree[h].u){
            for(int j = i;j <= rt;j++){
                if(y[j] != a[tree[h].u][tree[h].r][tot1]){
                    flag = 1;
                }
                tot1++;
            }
            if(!flag){

                if(i == 0) ff += 1;
                else ff += fg[i-1];
                //cout << ff << '@' << i;
            }
        }
    }
   // cout << endl;

    return ff;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> p;

    for(int i = 1;i <=n;i++){
        cin >> a[i][0] >>a[i][1];
        bu(a[i][0],i,1);
        bu(a[i][1],i,0);
        //cout <<a[i][0];
    }
    //f[0] = 1;
    for(int i = 1;i <=p;i++){
        string x,y;
        cin >> x >> y;
        for(int i = 0;i < x.size();i++){
            f[i] = 0;
            fg[i] = 0;
           // cout << x[i] << y[i];
            if(x[i] == y[i]){
                //cout << '#';
                if(i == 0){
                    f[i] = 1;
                    fg[i] = 1;
                }else f[i] = f[i-1];
                if(fg[i-1]){
                    fg[i] = 1;
                }
            }
            f[i] += cl(x,y,i);
           // cout << f[i] << ':' << fg[i] << ' ';
        }
        cout << f[x.size()-1] << endl;
    }

    return 0;
}
