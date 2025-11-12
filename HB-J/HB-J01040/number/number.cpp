#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int a[1000005],j=0;
int cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0' && s[i]<='9'){
            a[j]=(int)s[i]-48;
            j++;
        }
    }
    sort(a,a+l,cmp);
    for(int i=0;i<j;i++){
        cout << a[i];
    }
    return 0;
}
