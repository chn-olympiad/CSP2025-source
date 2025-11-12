#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1009]={0},n=0,m=0;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='9'){
            a[n]=9;
            n++;
        }if(s[i]=='8'){
            a[n]=8;
            n++;
        }if(s[i]=='7'){
            a[n]=7;
            n++;
        }if(s[i]=='6'){
            a[n]=6;
            n++;
        }if(s[i]=='5'){
            a[n]=5;
            n++;
        }if(s[i]=='4'){
            a[n]=4;
            n++;
        }if(s[i]=='3'){
            a[n]=3;
            n++;
        }if(s[i]=='2'){
            a[n]=2;
            n++;
        }if(s[i]=='1'){
            a[n]=1;
            n++;
        }if(s[i]=='0'){
            a[n]=0;
            n++;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            if(a[i]<a[j]){
                int q=a[i];
                a[i]=a[j];
                a[j]=q;
            }
        }
    }
    for(int i=0;i<n;i++){
        int q=1;
        for(int j=i+1;j<n;j++){
            q*=10;
        }
        m+=a[i]*q;
    }
    cout << m << endl;
    return 0;
}
