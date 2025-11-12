#include<bits/stdc++.h>
using namespace std;
string a[1000];
int main(){
    int b[1000];
    int s=0
    for(int i=1;i<=a.size();i++)
        cin>>a[i];

        if(a[i]>=21&&<=29)
        {
            b[s]=a[i];
            s++;

        }
        for(int j=0;j<=s;j++){
            if(b[j]>b[j-1])
            {
                swap([b[j],b[j-1]);
            }
        }
        for(int j=0;j<=s;j++){
           cout<<b[j];
        }



        return 0;
}

