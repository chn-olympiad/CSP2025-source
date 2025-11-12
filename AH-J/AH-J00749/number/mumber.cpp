#include<bits/stdc++/h>
using namespace std;
int n=100000;
int main()
{
    char s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    bool tured=false;
    int count=0,m=0,shuz[m];
    for(int i=0;i<n;i++)
    {
        if(s[i]>=0&&s[i]<=9){
             shuz[m]=s[i];
             m++;
             count++;
        }
    }
    for(int i=0;i<count;i++){
    for(int j=0;j<count;j++){
       int maxshu=shuz[0];
       if(shuz[i]>maxshu)maxshu=shuz[i];
    }
    cout<<maxshu;
    count--;
    }
    return 0;
}
