#include<bits/stdc++.h>
#define I using
#define AK namespace
#define CSP std;
I AK CSP
#define ll long long
int num[10];
int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int siz=s.size();
    for(int i=0;i<siz;i++){
        char ch;
        if('0'<=s[i]<='9'){
            ch=s[i];
            switch(ch){
                case '0':num[0]++;break;
                case '1':num[1]++;break;
                case '2':num[2]++;break;
                case '3':num[3]++;break;
                case '4':num[4]++;break;
                case '5':num[5]++;break;
                case '6':num[6]++;break;
                case '7':num[7]++;break;
                case '8':num[8]++;break;
                case '9':num[9]++;
            }
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<num[i];j++){
            cout<<i;
        }
    }
    cout<<endl;

    return 0;
}
