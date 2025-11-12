#include <bits/stdc++.h>
using namespace std;
#define zd long long

int FoundMax(int a,int b){
    return (a>b);
}

int GetStrLen(string a){
    int ctd=0;
    while (a!=""){
        if (a[ctd]!='\0'){
            ctd++;
        }
        else{
            break;
        }
    }
    return ctd;
}

int main()
{
    ifstream read_f;
    read_f.open("number.in");
    string Num;
    read_f>>Num;
    zd lenNum = GetStrLen(Num);
    zd a[1000000];
    int ctn=0;
    for (int i = 0;i<=lenNum;i++){
        if ((int)Num[i]-48<10&&(int)Num[i]-48>=0){
            a[ctn]=Num[i]-48;
            ctn++;
        }
    }
    sort(a,a+ctn,FoundMax);
    ofstream save_f;
    save_f.open("number.out");
    for(int i=0;i<ctn;i++){
        save_f<<a[i];
    }
    return 0;
}
