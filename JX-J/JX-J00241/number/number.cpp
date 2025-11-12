#include<iostream>
using namespace std;
int a[10100];
int main(){
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
    int c=0,l;
    string s;
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0' and s[i]<='9'){
            a[i]=s[i];
            c++;
        }
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<=l-i;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=0;i<c;i++){
        cout<<a[i]-48;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
