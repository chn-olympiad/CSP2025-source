#include<bits/stdc++.h>
using namespace std;
long long l1,l2=0,ze=0,i,a[1000005];
string s1;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    //cout<<"1\n1\n4\n5\n";//noi linux can \n
    ///*
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //*/
    cin>>s1;
    l1=s1.size();
    for(i=0;i<l1;i++)
    {
        if(s1[i]>='0'&&s1[i]<='9')
        {
            a[l2]=s1[i]-48;
            l2++;
            if(s1[i]==48) ze++;
        }
    }
    if(ze==l2)
    {
        printf("0");
        return 0;
    }
    sort(a,a+l2,cmp);
    for(i=0;i<l2;i++) printf("%lld",a[i]);
    return 0;
}
/*
*/
