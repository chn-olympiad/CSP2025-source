#include<bits/stdc++.h>
using namespace std;
string s;
string a[100000];
int l;
int main(){
    cin>>s;
    for(int i=0;i<=10000;i++){
        if(s[i]=="1") {
            a[l]=s[i];
            l+=1;        }
        else if(s[i]=="2") {
                a[l]=s[i];
                l+=1;        }
        else if(s[i]=="3") {
                a[l]=s[i];
                l+=1;        }
        else if(s[i]=="4") {
                a[l]=s[i];
                l+=1;        }
        else if(s[i]=="5") {
                a[l]=s[i];
                l+=1;        }
        else if(s[i]=="6") {
                a[l]=s[i];
                l+=1;        }
        else if(s[i]=="7") {
                a[l]=s[i];
                l+=1;        }
        else if(s[i]=="8") {
                a[l]=s[i];
                l+=1;        }
        else if(s[i]=="9") {
                a[l]=s[i];
                l+=1;        }
        else if(s[i]=="0") {
                a[l]=s[i];
                l+=1;        }
    }
    sort(a,a+l+1);
    for(int i=l;i>=0;i-=1){
        cout<<a[i];
        }
    return 0;
}


