#include<iostream>
#include<cstring>
using namespace std;
int b[100000001];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long i=0,j=1;
    while(s[i]){
        if(s[i]>=97&&s[i]<=122){

        }
        else b[j++]=s[i]-48;
        i++;
    }
    for(long long k=1;k<=j-1;k++){
        for(int l=1;l<=j-1;l++){
            if(b[l]<b[l+1]){
                swap(b[l],b[l+1]);
            }
        }
    }
    for(long long i=1;i<=j-1;i++){
        cout<<b[i];
    }

    return 0;

}
