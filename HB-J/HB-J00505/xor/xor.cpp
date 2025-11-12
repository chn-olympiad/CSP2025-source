#include <bits/stdc++.h>
using namespace std;

int cnt=0,res=0;
long long n,k;
long long a[5*100000+10];
long long xom[5*100000+10];
map<long long,bool> book;



int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    xom[0]=0;
    for(int i=1;i<=n;i++) cin >> a[i],xom[i]=xom[i-1]^a[i];

    for(int i=n;i>=0;i--){
        if(book[k^xom[i]]){
            cnt++;
            book.clear();
        }
        book[xom[i]]=1;
    }cout << cnt;

    return 0;
}
/*
i think my code is too simple,can i Ac?
*/
