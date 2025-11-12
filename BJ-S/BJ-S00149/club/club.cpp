#include <bits/stdc++.h>
using namespace std;
int t;//time
//1~5
int n;//num of person
//2~10**5
int sub[100005][2];
int n_[4];
int l1,l2,l3;
int l;
int m;
int k;
int list_[50005];
inline int sub_(int a1,int a2,int a3){
    int t;
    if (a1<a2){
        t = a1;
        a1 = a2;
        a2 = t;
    }
    if (a2<a3){
        t = a3;
        a3 = a2;
        a2 = t;
    }
    if (a1<a2){
        t = a1;
        a1 = a2;
        a2 = t;
    }
    return a1-a2;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;

    for (int ti=0;ti<t;ti++){
        memset(n_,0,sizeof(n_));
        memset(sub,0,sizeof(sub));
        memset(list_,0,sizeof(list_));
        l = 0;
        m = 0;
        k = 0;
        cin >> n;
        for (int i=0;i<n;i++){
            cin >> l1 >> l2 >> l3;
            if (l1>=l2&l1>=l3){
                l += l1;
                sub[i][1] = 1;
                n_[1]++;
            }
            else if(l2>=l1&l2>=l3){
                l += l2;
                sub[i][1] = 2;
                n_[2]++;
            }
            else{
                l += l3;
                sub[i][1] = 3;
                n_[3]++;
            }
            sub[i][0] = sub_(l1,l2,l3);
        }
        if (n_[1]>n/2) m=1;
        if (n_[2]>n/2) m=2;
        if (n_[3]>n/2) m=3;
        if (m){
            for (int j=0;j<n;j++){
                if (sub[j][1]==m){
                    list_[k] = sub[j][0];
                    k++;
                }
            }
            for (int j=0;j<n_[m]-1;j++){
                for (int w=j+1;w<n_[m];w++){
                    if (list_[j]>list_[w]){
                        swap(list_[j],list_[w]);
                    }
                }
            }
            for (int j=0;j<n_[m]-(n/2);j++){
                l -= list_[j];
            }
        }
        cout << l << endl;
    }
    return 0;
}