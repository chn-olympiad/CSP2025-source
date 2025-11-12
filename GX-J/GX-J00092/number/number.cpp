#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string a,b;
    cin >> a;
    for(char i : a){
        if(i == '1' || i == '2' || i == '3' || i == '4' || i == '5' || i == '6' || i == '7' || i == '8' || i == '9' || i == '0') {
            b += i;
        }
    }
   sort(b.begin(),b.end());
   for (int i=b.size()-1;i<b.size();i--) {
      cout << b[i];
   }
   return 0;
}
