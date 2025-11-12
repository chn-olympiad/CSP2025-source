#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a1[200001][1000000],a2[200001][1000000],b1[200001][1000000],b2[200001][1000000],str2[1000000];
int n,q;
bool check(int a,int b,int k,char str2[1000000]){
    bool check = true;
    int j = 0;
    for (int i = a;i <= b;i++){
        if (!(str2[j]==a1[k][i])){
            check = false;
        }
        j++;
    }
    return check;
}
void replace(int i,int j,char str2[1000000],char str[100]){
    int n = 0;
    for (int k = i;k <= j;k++){
        str2[k] = str[n];
        n++;
    }
}
int dfs(int k,char str[100]){
    int len = strlen(a1[k]),cnt = 0,len2;
    for (int i = 0;i < len-1;i++){
        for (int j = i+1;j < len;j++){
            for (int m = 0;m < q;m++){
                len2 = strlen(b1[m]);
                if (check(i,j,k,b1[m])&&len2 == j-i+1){
                    replace(i,j,a1[k],b2[m]);
                    if (check(0,len-1,k,str2)){
                        cnt++;
                    }
                }
            }
        }
    }
    return cnt;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for (int i = 0;i < n;i++){
        cin >> b1[i] >> b2[i];
    }
    for (int j = 0;j < q;j++){
        cin >> a1[j] >> a2[j];
    }
    for (int k = 0;k < q;k++){
        cout << dfs(k,a1[k]) << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
