#include<bits/stdc++.h>

using namespace std;

string s;

long long shu[10];

int main(){

    freopen("number.in","r",stdin);

    freopen("number.out","w",stdout);

    cin>>s;

    for(int i=0;i<s.size();i++){

        switch(s[i]-'0'){

            case 0:shu[0]++;break;

            case 1:shu[1]++;break;

            case 2:shu[2]++;break;

            case 3:shu[3]++;break;

            case 4:shu[4]++;break;

            case 5:shu[5]++;break;

            case 6:shu[6]++;break;

            case 7:shu[7]++;break;

            case 8:shu[8]++;break;

            case 9:shu[9]++;break;

        }

    }

    for(int i=9;i>=0;i--){

        for(int j=0;j<shu[i];j++){

            cout<<i;

        }

    }

    return 0;

}
