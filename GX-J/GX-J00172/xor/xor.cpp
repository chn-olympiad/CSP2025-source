#include<bits/stdc++,h>
using namespace std;
string n;
long long m[100006];
int main(){
   cin>>n;
    for(int i=1;i<=size.n;i++){
        m[i]=n[i]-'0';
    }
    for(int i=1;i<=size.n;i++){
        for(int j=1;j<=i;j++){
            if(m[j],m[j+1]){
                int t=m[j+1];
                m[j+1]=m[j];
                m[j]=t;
            }
        }
    }

    return 0;
}
