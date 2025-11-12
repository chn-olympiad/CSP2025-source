#include<bits/stdc++.h>
using namespace std;

vector<long long> j;
vector<long long> p;
bool pd(long long t){
    for(int i=0;i<p.size();i++){
        if(p[i] == t){
            return false;
        }
    }
    return true;
}

int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
long long n,k,ans=0;
cin >> n >> k;
for(long long i=0;i<n;i++){
    long long tmp;
    cin >> tmp;
    j.push_back(tmp);
    if(tmp == k){
        ans++;
        p.push_back(i);
    }
}
for(long long i=0;i<j.size();i++){
    long long z=i+1;
    if(pd(i)){
        long long s=j[i];

        while(z<=j.size()-1 && pd(z)){
            if((s|j[z])!=k && s==k){
                ans++;
            }
            s= s | j[z];
            z++;
        }
        if(s == k){
            ans++;
        }
    }
}
 cout << ans;

fclose(stdin);
fclose(stdout);

return 0;
}
