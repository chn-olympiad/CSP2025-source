#include <bits/stdc++.h>
using namespace std;
int sort2(int a,int b){
    return a > b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string line;
    getline(cin,line);
    char ans[1000005];
    int index = 0;
    for (int i = 0;i < line.length();i++){
        if (line[i] <= '9' && line[i] >= '0'){
            ans[index] = line[i];
            index++;
        }
    }
    sort(ans,ans+index);
    cout << ans;

    fclose(stdin);
    fclose(stdout);
}