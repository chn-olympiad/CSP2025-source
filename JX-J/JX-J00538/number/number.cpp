#include<bits/stdc++.h>
using namespace std;

int a[1000000];

int sort(int sa,int sb){
    return sa>sb;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int t=0;t<s.size();t++){
        a[t]=s[t]-'0';
    }
    sort(a,a+s.size());
    for(int t=s.size()-1;t>=0;t--){
        cout<<a[t];
    }
    return 0;
}



// 000 0  0    0        0000000     ######     #
//   0 0 0    000 0000        0          #    #
// 000 00      0     0  0000000          #   #
// 0   00000 00000 000        0     ######  #
// 000 00    0 0  0     0000000     #     #######
//   0 0 0   0000 0000   0 0 0      #      #
//  00 0  00 0 00000000    0        ######  #
//                       0   0           #   #
//                                       #    #
//                                    ####     ##
