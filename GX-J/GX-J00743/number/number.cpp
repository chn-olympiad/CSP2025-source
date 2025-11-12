#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]<='9'&&s[i]>='0'){
            switch(s[i]){
                case '1':
                    a[1]++;
                    break;
                case '2':
                    a[2]++;
                    break;
                case '3':
                    a[3]++;
                    break;
                case '4':
                    a[4]++;
                    break;
                case '5':
                    a[5]++;
                    break;
                case '6':
                    a[6]++;
                    break;
                case '7':
                    a[7]++;
                    break;
                case '8':
                    a[8]++;
                    break;
                case '9':
                    a[9]++;
                    break;
                case '0':
                    a[0]++;
                    break;
            }
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=a[i];j>0;j--){
            cout<<i;
        }
    }
    return 0;
}
