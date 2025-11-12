#include <iostream>

using namespace std;

long long tong[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++){
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
            tong[s[i] - '0']++;
        }
    }
    for(int i = 9;i >= 0;i--){
        for(int j = 1;j <= tong[i];j++){
            printf("%d",i);
        }
    }
    printf("\n");
    return 0;
}
