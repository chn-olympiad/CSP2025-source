#include<bits/stdc++.h>
using namespace std;
string s;
long long a[5005]={0},i=0,j=0,zh=0;
int main(){
    freopen(number.in,"r",stdin);
    freopen(number.out,"w",stdout);
    cin>>s;
    while(true){
        if(s[i]){
            if(s[i]=='1'){
                a[j]=1;
                j++;
            }
            if(s[i]=='2'){
                a[j]=2;
                j++;
            }
            if(s[i]=='3'){
                a[j]=3;
                j++;
            }
            if(s[i]=='4'){
                a[j]=4;
                j++;
            }
            if(s[i]=='5'){
                a[j]=5;
                j++;
            }
            if(s[i]=='6'){
                a[j]=6;
                j++;
            }
            if(s[i]=='7'){
                a[j]=7;
                j++;
            }
            if(s[i]=='8'){
                a[j]=8;
                j++;
            }
            if(s[i]=='9'){
                a[j]=9;
                j++;
            }
            if(s[i]=='0'){
                a[j]=0;
                j++;
            }

        }else{
            break;
        }
        i++;

    }
    sort(a,a+j);
    for(int k=0,cf=1;k<=j;k++){
        zh=zh+a[k]*cf;
        cf=cf*10;
    }
    cout<<zh;




}
