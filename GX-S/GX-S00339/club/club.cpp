// #include <bits/stdc++.h>
// using namespace std;

// int t, n, a, b, c, tot;
// struct degr{
//     int l1, l2, l3, c[3];
// }d[100010];

// bool cmp(int x, int y){
//     return x > y;
// }

// bool cmp2(degr x, degr y){
//     //if(x.c[0] == y.c[0]){
//         if(x.c[2] == y.c[2]){
//             return x.c[1] > y.c[1];
//         }
//         return x.c[2] > y.c[2];
//     //}
//     //return x.c[0] > y.c[0];
// }

// void input(){
//     cin >> n;
//     a = 0;
//     b = 0;
//     c = 0;
//     tot = 0;
//     for(int i = 1; i <= n; i++){
//         cin >> d[i].l1 >> d[i].l2 >> d[i].l3;
//         d[i].c[0] = abs(d[i].l1 - d[i].l2);
//         d[i].c[1] = abs(d[i].l2 - d[i].l3);
//         d[i].c[2] = abs(d[i].l1 - d[i].l3);
//         sort(d[i].c, d[i].c + 3, cmp);
//     }
// }

// void getans(int t1, int t2, int &x, int &y){
//     int tmp = max(t1, t2);
//     if(tmp == t1){
//         if((x << 1) < n){
//             tot += t1;
//             x++;
//         }
//         else {
//             tot += t2;
//             y++;
//         }
//     }
//     else{
//         if((y << 1) < n){
//             tot += t2;
//             y++;
//         }
//         else {
//             tot += t1;
//             x++;
//         }
//     }
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
    
//     freopen("club.in", "r", stdin);
//     freopen("club.out", "w", stdout);

//     cin >> t;
//     while(t--){
//         input();
//         sort(d + 1, d + n + 1, cmp2);
// // ----------------------------------------------------------
//         for(int i = 1; i <= n; i++){
//             cout << d[i].l1 << " " << d[i].l2 << " " << d[i].l3 << " " << d[i].c[0] << " "<< d[i].c[1] << " " << d[i].c[2] << endl;  
//         }
// // ----------------------------------------------------------

//         for(int i = 1; i <= n; ++i){
//             int tmp = max(d[i].l1, max(d[i].l2, d[i].l3));
//             if(tmp == d[i].l1){
//                 if((a << 1) < n){
//                     tot += tmp;
//                     a++;
//                 }
//                 else getans(d[i].l2, d[i].l3, b, c);
//             }
//             else if(tmp == d[i].l2){
//                 if((b << 1) < n){
//                     tot += tmp;
//                     b++;
//                 }
//                 else getans(d[i].l1, d[i].l3, a, c);
//             }
//             else{
//                 if((c << 1) < n){
//                     tot += tmp;
//                     c++;
//                 }
//                 else getans(d[i].l1, d[i].l2, a, b);
//             }
// // ------------------------------------------------------------------- 
//             cout << a << " " << b << " " << c << endl;
// // -------------------------------------------------------------------
//         }
//         cout << tot << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int t, n, a, b, c, tot;
struct degr{
    int l1, l2, l3, c;
}d[100010];
struct cmp{
    bool operator()(degr x, degr y){
        return x.c > y.c;
    }
};
priority_queue<degr, vector<degr>, cmp> pqa, pqb, pqc; 

void gs(int x){
    int maxn = max(d[x].l1, max(d[x].l2, d[x].l3));
    tot += maxn;
    if(maxn == d[x].l1){
        d[x].c = d[x].l1 - max(d[x].l2, d[x].l3);
        pqa.push(d[x]);
    }
    else if(maxn == d[x].l2){
        d[x].c = d[x].l2 - max(d[x].l1, d[x].l3);
        pqb.push(d[x]);
    }
    else{
        d[x].c = d[x].l3 - max(d[x].l1, d[x].l2);
        pqc.push(d[x]);
    }
    
}

void input(){
    a = n;
    b = 0;
    c = 0;
    tot = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> d[i].l1 >> d[i].l2 >> d[i].l3;
        gs(i);
    }
}
void init(){
    while(!pqa.empty()) pqa.pop();
    while(!pqb.empty()) pqb.pop();
    while(!pqc.empty()) pqc.pop();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        init();
        input();
        while(pqa.size() > (n / 2)){
            tot -= pqa.top().c;
            pqa.pop();
        }
        while(pqb.size() > (n / 2)){
            tot -= pqb.top().c;
            pqb.pop();
        }
        while(pqc.size() > (n / 2)){
            tot -= pqc.top().c;
            pqc.pop();
        }
        cout << tot << endl;
    }
}