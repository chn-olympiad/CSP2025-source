#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
char s[maxn],num[maxn];
bool cmp(char a,char b){
    return a - '0' > b - '0';
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i = 1;
    while(s[i-1] != '\n'){
        s[i] = getchar();
        i++;
    }
    int id = i;
    int j = 0;
    for(int i = 1; i < id;i++){
        if(s[i] - '0' <= 9 && s[i] - '0' >= 0){
            j++;
            num[j] = s[i];
        }
    }
    sort(num+1,num+id,cmp);
    for(int i = 1;i <= j;i++){
        cout << num[i];
    }
    return 0;
}
