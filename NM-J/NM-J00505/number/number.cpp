#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string s;
int ans[10];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    getline(cin, s);
    if(s.size() == 1) cout << s;
    else{
        for(int i = 0;i < s.size();i++)
        {
            switch(s[i])
            {
                case '0':ans[0]++;break;
                case '1':ans[1]++;break;
                case '2':ans[2]++;break;
                case '3':ans[3]++;break;
                case '4':ans[4]++;break;
                case '5':ans[5]++;break;
                case '6':ans[6]++;break;
                case '7':ans[7]++;break;
                case '8':ans[8]++;break;
                case '9':ans[9]++;break;
            }
        }
        for(int i = 9;i >= 0;i--)
        {
            if(ans[i] >= 1)
            {
                int temp = ans[i];
                while(temp)
                {
                    cout << i;
                    temp--;
                }
            }
        }
    }
    return 0;
}
