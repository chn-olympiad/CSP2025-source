#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std ;
string a;
int s[1000005],cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<sizeof(a);i++){
        if(a[i]>='0' && a[i]<='9'){
            s[++cnt]=a[i]-'0';
        }
    }
    sort(s+1,s+cnt+1);
    for(int i=cnt;i>=1;i--){
        cout<<s[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

