#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int num[11];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    scanf("%s",s);
    int n = strlen(s);
    for(int i = 0 ; i < n ; i++ )
    {
        if(s[i] >= 'a' && s[i] <= 'z') continue;
        num[s[i]-'0']++;
    }
    for(int i = 9 ; i >= 0 ; i-- )
    {
        if(num[i] != 0)
        {
            int j = 0 ;
            while(j < num[i]){
                printf("%d",i);
                j++;
            }
        }
    }
    return 0 ;
}
