#include<bits/stdc++.h>
using namespace std;
string s;
int t[1000010],ttop=0;
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int Size=s.size();
    int t[Size];
    for(int i=0;i<Size;i++){
        if('0'<=s[i] && s[i]<='9'){
            t[++ttop]=int(s[i])-48;
        }
    }

    sort(t+1,t+ttop+1,cmp);
    for(int i=1;i<=ttop;i++){
        cout << t[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
