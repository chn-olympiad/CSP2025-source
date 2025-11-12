#include<bits/stdc++.h>
#define ll long long
using namespace std;
int const N=1e5;
string name;
ll m[N],j=0,num=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>name;
    for(int i=0;i<name.size();i++){
        if(name[i]=='0'){
            m[j]=0;
            j++;
        }if(name[i]=='1'){
            m[j]=1;
            j++;
        }if(name[i]=='2'){
            m[j]=2;
            j++;
        }if(name[i]=='3'){
            m[j]=3;
            j++;
        }if(name[i]=='4'){
            m[j]=4;
            j++;
        }if(name[i]=='5'){
            m[j]=5;
            j++;
        }if(name[i]=='6'){
            m[j]=6;
            j++;
        }if(name[i]=='7'){
            m[j]=7;
            j++;
        }if(name[i]=='8'){
            m[j]=8;
            j++;
        }if(name[i]=='9'){
            m[j]=9;
            j++;
        }
    }
    for(int i=0;i<j;i++){
        for(int k=0;k<j;k++){
            if(m[i]>m[k]){
                swap(m[i],m[k]);
            }
        }
    }
    for(int i=0;i<j;i++){
        cout<<m[i];
    }
}
