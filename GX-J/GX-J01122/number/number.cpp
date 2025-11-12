#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char mo[1000010];
    char ans[1000010];
    int kk[1000010];
    string a;
    cin>>a;
    long long f;
    f = a.length();
    long long fff = 0;
    for(long long i = 0 ; i < f ; i++){
        if(a[i]>='0'&&a[i]<='9'){
            mo[fff] = a[i];
            fff++;
        }
    }
    if(fff == 1){
        int k = int(mo[0]) - 48;
        cout<<k;
        return 0;
    }

    for(long long i = 0; i < fff; i++){
        kk[i] = int(mo[i])-48;
    }
    long long a0 = 0;
    long long a1 = 0;
    long long a2 = 0;
    long long a3 = 0;
    long long a4 = 0;
    long long a5 = 0;
    long long a6 = 0;
    long long a7 = 0;
    long long a8 = 0;
    long long a9 = 0;
    for(long long i = 0;i<fff;i++){
        if (kk[i] == 9) a9++;
        if (kk[i] == 8) a8++;
        if (kk[i] == 7) a7++;
        if (kk[i] == 6) a6++;
        if (kk[i] == 5) a5++;
        if (kk[i] == 4) a4++;
        if (kk[i] == 3) a3++;
        if (kk[i] == 2) a2++;
        if (kk[i] == 1) a1++;
        if (kk[i] == 0) a0++;
    }
    long long v = 0;
    for(long long i = 0; i<a9;i++){
        ans[v] = '9';
        v++;
    }
    for(long long i = 0; i<a8;i++){
        ans[v] = '8';
        v++;
    }
    for(long long i = 0; i<a7;i++){
        ans[v] = '7';
        v++;
    }
    for(long long i = 0; i<a6;i++){
        ans[v] = '6';
        v++;
    }
    for(long long i = 0; i<a5;i++){
        ans[v] = '5';
        v++;
    }
    for(long long i = 0; i<a4;i++){
        ans[v] = '4';
        v++;
    }
    for(long long i = 0; i<a3;i++){
        ans[v] = '3';
        v++;
    }
    for(long long i = 0; i<a2;i++){
        ans[v] = '2';
        v++;
    }
    for(long long i = 0; i<a1;i++){
        ans[v] = '1';
        v++;
    }
    for(long long i = 0; i<a0;i++){
        ans[v] = '0';
        v++;
    }
    //hhh









    long long g = fff;
    long long ans1 = 0;
    int d = 1;
    int kennys;
    for(long long i = 0;i<fff;i++){
        kennys = int(ans[i])-48;
        for(int j = 1;j<g;j++){
            d*=10;
        }
        ans1 += d*kennys;
        g--;
        d = 1;
    }
    cout<<ans1;
	return 0;
}
