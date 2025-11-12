#include<bits/stdc++.h>
using namespace std;

const int maxn=5*10e5;
int n,k,a_i,cnt=0,a[maxn+5]={};

int main(){
	freopen("number.in" ,"r" ,stdin );
	freopen("number.ans","w" ,stdout);

    cin >> n >> k >> a[0];
    for(int i=1; i<n; i++){
        cin >> a_i;
        a[i] = a[i-1] ^ a_i;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[i]^a[j] == k) cnt = max(i-j, cnt);
        }
    }

    cout << cnt;

    fclose(stdin );
    fclose(stdout);
    return 0;
}
