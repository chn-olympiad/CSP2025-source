#include <bits/bits/stdc++.h>
using namespace std;

int a[101],n,m,s,t,q;

int main(){
cin >> n >> m;
l = n * m;
for(int i = 1;i <= l;i++)
    cin >> a[i];
for(int i = 1;i <= l;i++)
    for(int j = 1;j <= l;j++)
        if(a[j] < a[j + 1]){
            t = a[j];
            a[j] = a[j + 1];
            a[j + 1] = t;
        }
q = (s - 1) / n + 1;
if(q % 2 == 0)
    cout << q << " " << ((s - 1) % n) + 1;
else
    cout << q << " " << s % n;
return 0;
}
