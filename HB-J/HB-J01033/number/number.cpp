#include<bits//stdc++.h>
using namespace std;
string s;
char a[1000003];
int m,n=0,k=0,d=0,e,j;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    m=s.size();
    for(int i=0;i<m;i++){
        if(s[i]*1>47&&s[i]*1<58){
            a[n]=s[i];
            n++;
        }
    }for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(k<=a[j]-'0'){
                k=a[j]-'0';
                e=j;
            }
        }a[e]=-1;
        d=d*10+k;
        k=0;
    }cout<<d;
    return 0;
}
