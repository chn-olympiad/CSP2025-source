#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int num[1000010],k=0,l=0;
    while(cin >> s[k]){
        if(s[k]<='9'&&s[k]>='0'){
            num[l]=s[k]-'0';
        }
        k++;
    }
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<l;j++){
            if(num[j]>num[i]){
                swap(num[i],num[j]);
            }
        }
    }
    for(int i=0;i<l;i++){
        cout << num[i];
    }




























































































    //沙比CCF
    return 0;
}
