#include <bits/stdc++.h>
using namespace std;
int t;
const int N = 20005;
struct person{
    int a, b, c;
    bool hd;
};
bool cmp1(person x, person y){
    return x.a > y.a;
}
bool cmp2(person x, person y){
    return x.b > y.b;
}
bool cmp3(person x, person y){
    return x.c > y.c;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    while(t--){
        int n;
        int ans = 0;
        int s1 = 0, s2 = 0, s3 = 0;
        cin>>n;
        vector<person> people;
        for(int i = 1, a, b, c;i<=n;i++){
            cin>>a>>b>>c;
            people.push_back({a, b, c, false});
        }
        bool f2 = true;
        for(int i = 0;i<n;i++){
            if(people[i].b != 0 || people[i].c != 0) f2 = false;
        }
        if(f2){
            sort(people.begin(), people.end(), cmp1);
            for(int i = 0;i<n/2;i++){
                ans+= people[i].a;
            }
            cout<<ans<<endl;
            continue;
        }
        sort(people.begin(), people.end(), cmp1);
        for(int i = 0, k = 1;i<n;i++){
            if(k > n/2) break;
            if(people[i].a >= people[i].b && people[i].a >= people[i].c){
                ans += people[i].a;
                people[i].hd = true;
                k++;
                s1++;
            }
        }
        sort(people.begin(), people.end(), cmp2);
        for(int i = 0, k = 1;i<n;i++){
            if(k > n/2) break;
            if(people[i].hd) continue;
            if(people[i].b >= people[i].a && people[i].b >= people[i].c){
                ans += people[i].b;
                people[i].hd = true;
                k++;
                s2++;
            }
        }
        sort(people.begin(), people.end(),cmp3);
        for(int i = 0, k = 1;i<n;i++){
            if(k > n/2) break;
            if(people[i].hd) continue;
            if(people[i].c >= people[i].a && people[i].c >= people[i].b){
                ans += people[i].c;
                people[i].hd = true;
                k++;
                s3++;
            }
        }
        for(int i = 0;i<n;i++){
            if(people[i].hd) continue;
            int a = people[i].a, b = people[i].b, c = people[i].c;
            if(a >= b && a >= c && s1 < n/2){
                ans += people[i].a;
                s1++;
            }
            else if(b >= a && b >= c && s2 < n/2){
                ans += people[i].b;
                s2++;
            }
            else{
                ans += people[i].c;
                s3++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
