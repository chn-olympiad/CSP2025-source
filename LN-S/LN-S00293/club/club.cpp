#include <bits/stdc++.h>
using namespace std;

struct person{
    int a;
    int b;
    int c;
    int state;
};
int t,n;

bool comp1(person a,person b){
    return a.a>b.a;
}

bool comp2(person a,person b){
    return a.b>b.b;
}

bool comp3(person a,person b){
    return a.c>b.c;
}

int a1(int n,vector<person> vec){
    long long sum=0;
    sort(vec.begin(),vec.end(),comp1);
    int n_a=0;
    for (int i=0;i<n;i++){
        if (vec[i].a>=vec[i].b && vec[i].a>=vec[i].c && n_a*2 < n && vec[i].state!=1){
            n_a++;
            sum+=vec[i].a;
            vec[i].state=1;
        } else if (n_a*2>=n){
            break;
        }
    }
    sort(vec.begin(),vec.end(),comp2);
    int n_b=0;
    for (int i=0;i<n;i++){
        if (vec[i].b>=vec[i].c && n_b*2 < n  && vec[i].state!=1){
            n_b++;
            sum+=vec[i].b;
            vec[i].state=1;
        } else if (n_b*2>=n){
            break;
        }
    }
    sort(vec.begin(),vec.end(),comp3);

    int n_c=0;
    for (int i=0;i<n;i++){
        if (n_c*2 < n && vec[i].state!=1){
            n_c++;
            sum+=vec[i].c;
            vec[i].state=1;
        } else if (n_c*2>=n){
            break;
        }
    }
    return sum;
}
int a2(int n,vector<person> vec){
    long long sum=0;
    sort(vec.begin(),vec.end(),comp2);
    int n_b=0;
    for (int i=0;i<n;i++){
        if (vec[i].b>=vec[i].a && vec[i].b>=vec[i].c && n_b*2 < n && vec[i].state!=1){
            n_b++;
            sum+=vec[i].b;
            vec[i].state=1;
        } else if (n_b*2>=n){
            break;
        }
    }
    sort(vec.begin(),vec.end(),comp1);
    int n_a=0;
    for (int i=0;i<n;i++){
        if (vec[i].a>=vec[i].c && n_a*2 < n  && vec[i].state!=1){
            n_a++;
            sum+=vec[i].a;
            vec[i].state=1;
        } else if (n_a*2>=n){
            break;
        }
    }
    sort(vec.begin(),vec.end(),comp3);

    int n_c=0;
    for (int i=0;i<n;i++){
        if (n_c*2 < n && vec[i].state!=1){
            n_c++;
            sum+=vec[i].c;
            vec[i].state=1;
        } else if (n_c*2>=n){
            break;
        }
    }
    return sum;
}
int fuc(int n,vector<person> vec){
    int sum1=a1(n,vec);
    int sum2=a2(n,vec);
    return max(sum1,sum2);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n;
        vector<person> vec(100001);
        for (int j=0;j<n;j++){
            cin >> vec[j].a >> vec[j].b >> vec[j].c;
            vec[i].state=0;
        }
        cout << fuc(n,vec) << '\n';
    }
    return 0;
}
