#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ll long long
#define endl "\n"
int t;
int n , sum;
bool A = true , B = true , C = true;
struct node{
    int first , second , third;
} a[100010];
bool cmpA (node a , node b) {
    return a.first > b.first;
}
bool cmpB (node a , node b) {
    return a.second > b.second;
}
bool cmpC (node a , node b) {
    return a.third > b.third;
}
bool cmpAB (node a , node b) {
    return a.first - a.second > b.first - b.second;
}
bool cmpAC (node a , node b) {
    return a.first - a.third > b.first - b.third;
}
bool cmpBC (node a , node b) {
    return a.second - a.third > b.second - b.third;
}
int main(){
    IOS
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while (t--) {
        sum = 0;
        cin >> n;
        A = B = C = true;
        for (int i = 1 ; i <= n ; i ++ ) {
            cin >> a[i].first >> a[i].second >> a[i].third;
            if (a[i].first != 0) A = false;
            if (a[i].second != 0) B = false;
            if (a[i].third != 0) C = false;
        }
        if (!A && !B && !C) {
            //cout << "A B C" << endl;
            for (int i = 1 ; i <= n ; i ++ ) sum += max (a[i].first , max (a[i].second , a[i].third));\
            cout << sum << endl;
        } else if (!A && !B) {
            //cout << "A B" << endl;
            sort (a + 1 , a + 1 + n , cmpAB);
            for (int i = 1 ; i <= n / 2 ; i ++ ) sum += a[i].first;
            for (int i = n / 2 + 1 ; i <= n ; i ++ ) sum += a[i].second;
            cout << sum << endl;
        } else if (!B && !C) {
            //cout << "B C" << endl;
            sort (a + 1 , a + 1 + n , cmpBC);
            for (int i = 1 ; i <= n / 2 ; i ++ ) sum += a[i].second;
            for (int i = n / 2 + 1 ; i <= n ; i ++ ) sum += a[i].third;
            cout << sum << endl;
        } else if (!A && !C) {
            //cout << "A C" << endl;
            sort (a + 1 , a + 1 + n , cmpAC);
            for (int i = 1 ; i <= n / 2 ; i ++ ) sum += a[i].first;
            for (int i = n / 2 + 1 ; i <= n ; i ++ ) sum += a[i].third;
            cout << sum << endl;
        } else if (!A) {
            //cout << "A" << endl;
            sort (a + 1 , a + 1 + n , cmpA);
            for (int i = 1 ; i <= n / 2 ; i ++ ) sum += a[i].first;
            cout << sum << endl;
        } else if (!B) {
            //cout << "B" << endl;
            sort (a + 1 , a + 1 + n , cmpB);
            for (int i = 1 ; i <= n / 2 ; i ++ ) sum += a[i].second;
            cout << sum << endl;
        } else if (!C) {
            //cout << "C" << endl;
            sort (a + 1 , a + 1 + n , cmpC);
            for (int i = 1 ; i <= n / 2 ; i ++ ) sum += a[i].third;
            cout << sum << endl;
        }
    }
    return 0;
}
