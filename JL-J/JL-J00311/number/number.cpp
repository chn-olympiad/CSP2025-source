#include <iostream>
using namespace std;
string s;
int a[1000000],n=0,b[100000000],maxa,m=0,g=0;
int main(){
 //   freopen("number.in","r",std);
   // freopen("number.out","w",std);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            a[n]+=(int)(s[i]);
            n++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            if(a[j]>maxa){
                maxa=a[j];
                g=j;
            }
        }
        b[m]=maxa;
        m++;
        a[g]=0;
        maxa=0;
    }
    for(int i=0;i<m;i++){
        cout<<b[i];
    }
    return 0;
}
