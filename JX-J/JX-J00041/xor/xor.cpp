#include<bits/stdc++.h>
#define PII pair<int,int>
#define one first
#define tow second

using namespace std;

const int N = 5e5+10;
int a[N],s[N];
vector<PII>v;
int n,k;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        s[i] = s[i-1]^a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            int x = s[j]^s[i-1];
            if(x == k){
                v.push_back({i,j});
            }
        }
    }
    printf("%d",v.size());
    return 0;
}
