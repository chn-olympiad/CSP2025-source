#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;
string s;
int a[1000005];
long long k;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48&&s[i]<=57){
            k++;
            a[k]=(int)(s[i]);
        }
    }
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++){
        cout<<a[i]-48;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
