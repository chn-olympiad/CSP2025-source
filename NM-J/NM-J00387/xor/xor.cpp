#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,k,a[5*N];
vector<int> v1,v2;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        int m=i;
        while (m<=n) {
            int num=a[i];
            for (int j=i;j<m;j++) num^=a[j+1];
            if (num==k) {
                int len=v1.size();
                bool f=1;
                for (int i=0;i<len;i++) {
                    if (v1[i]>=i && v1[i]<=m) {
                        f=0;
                        break;
                    }
                    if (v1[i]<=i && i<=v2[i]) {
                        f=0;
                        break;
                    }
                    if (v2[i]>=i && v2[i]<=m) {
                        f=0;
                        break;
                    }
                    if (v1[i]<=m && m<=v2[i]) {
                        f=0;
                        break;
                    }
                }
                if (f==1) {
                    v1.push_back(i);
                    v2.push_back(m);
                }
            }
            m++;
        }
    }
    cout<<v1.size();
    return 0;
}
