#include <iostream>
#include<cstring>

using namespace std;
string nastr;
int a[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>nastr;
    for(int i=0;i<nastr.size();i++){
        if(nastr[i]>='0'&&nastr[i]<='9'){
            a[nastr[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
