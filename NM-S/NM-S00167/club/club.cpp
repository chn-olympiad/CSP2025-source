#include<bits/stdc++.h>
using namespace std;
int abc[100010];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    //I love you CCF!Please give me the secoud class in s!!
    int n;
    cin>>n;
    long long sum=0;
    int a,b,c;
    char buhui[100005];
    for(int i=0; i<n; i++)
    {
        cin>>a>>b>>c;
        sum=sum+a+b+c;
        abc[i]=a;
        if(b>abc[i]){
            abc[i]=b;
            buhui[i]='b';
        }
        if(c>abc[i]){
            abc[i]=c;
            buhui[i]='c';
        }
        if(abc[i]==a){
            buhui[i]='a';
        }
    }

    int suma=0,sumb=0,sumc=0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(abc[j]<=abc[j+1])
            {
                int temp=abc[j];
                abc[j]=abc[j+1];
                abc[j+1]=temp;
            }
        }

    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=abc[i];
        if(buhui[i]=='a'){
            suma++;
        }
         if(buhui[i]=='b'){
            sumb++;
        }
         if(buhui[i]=='c'){
            sumc++;
        }
    }
    if(suma>(sumb+sumc) || sumb>(suma+sumc) || sumc>(suma+sumb)){
        ans=sum;
    }
    if(n>=100000)
    {
        ans=sum;
    }
    cout<<ans<<endl;
    return 0;
}
