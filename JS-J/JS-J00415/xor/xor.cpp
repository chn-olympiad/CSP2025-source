#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    int a[n] = {0};
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int num = 0;
    for(int l = 0;l < n;l++){
        for(int r = l;r < n;r++){
            if(l == r){
                if(a[l] == k){
                    num++;
                }
            }else{
                int _sum = a[l];
                for(int z = l + 1;z <= r;z++){
                    _sum = _sum ^ a[z];
                }
                if(_sum == k){
                    num++;
                }
            }
        }
    }
    cout << num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
