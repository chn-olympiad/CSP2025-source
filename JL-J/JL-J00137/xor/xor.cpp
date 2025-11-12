#include<bits/stdc++.h>
using namespace std;
int maxnum = 0, n, k;
int a[500000];
bool two[20];
void over(){
    two[0] = false;
    two[1] = false;
    two[2] = false;
    two[3] = false;
    two[4] = false;
    two[5] = false;
    two[6] = false;
    two[7] = false;
    two[8] = false;
    two[9] = false;
    two[10] = false;
    two[11] = false;
    two[12] = false;
    two[13] = false;
    two[14] = false;
    two[15] = false;
    two[16] = false;
    two[17] = false;
    two[18] = false;
    two[19] = false;
    return ;
}
void dfs(int f,int sum){
    int sumxor = 0;
    if( f == n ){
        maxnum = max(sum, maxnum);
        return ;
    }
    two[0] = two[0] ^ bool(a[f]%1/0.5);
    two[1] = two[1] ^ bool(a[f]%2/1);
    two[2] = two[2] ^ bool(a[f]%4/2);
    two[3] = two[3] ^ bool(a[f]%8/4);
    two[4] = two[4] ^ bool(a[f]%16/8);
    two[5] = two[5] ^ bool(a[f]%32/16);
    two[6] = two[6] ^ bool(a[f]%64/32);
    two[7] = two[7] ^ bool(a[f]%128/64);
    two[8] = two[8] ^ bool(a[f]%256/128);
    two[9] = two[9] ^ bool(a[f]%512/256);
    two[10] = two[10] ^ bool(a[f]%1024/512);
    two[11] = two[11] ^ bool(a[f]%2048/1024);
    two[12] = two[12] ^ bool(a[f]%4096/2048);
    two[13] = two[13] ^ bool(a[f]%8192/4096);
    two[14] = two[14] ^ bool(a[f]%16384/8192);
    two[15] = two[15] ^ bool(a[f]%32768/16384);
    two[16] = two[16] ^ bool(a[f]%131072/65536);
    two[18] = two[18] ^ bool(a[f]%262144/131072);
    two[19] = two[19] ^ bool(a[f]%524288/262144);
    for(int i=0; i<20; i++){
        sumxor += pow(2,i) * two[i];
    }
    if( sumxor == k ){
        sumxor = 0;
        over();
        dfs(f+1, sum+1);
    }else{
        dfs(f+1, sum);
    }
    return ;
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    over();
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        dfs(i,0);
    }
    cout << maxnum ;
    return 0;
}
