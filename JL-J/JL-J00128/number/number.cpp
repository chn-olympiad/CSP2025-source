#include<iostream>
using namespace std;
int a[10000001];
int b[10000001];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);

    string s;
    cin>>s;
    int sum=0,maxn=-1,m=0;
    for(int i=0;i<s.size();i++){
        a[i]=s[i];
         }
    for(int  i=0;i<s.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[i]=a[i]-'0';
            sum++;
        }
        }
        for(int i=0;i<sum;i++){
            for( int i=0;i<sum;i++){
                    if(b[i]>=maxn){
                    maxn=b[i];
                    m=i;
                }
            }
            b[m]=-2;
            cout<<maxn;
            maxn=-1;
            m=0;

        }
    return 0;
}
