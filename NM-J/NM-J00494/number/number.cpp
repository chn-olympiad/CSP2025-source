// lms Done at 1761960693.1224391
#include <iostream>
#include <cstdio>
#include <string>
#include <ctype.h> // isdigit()
#include <vector>
#include <algorithm> // sort()
using namespace std;
string s = "";
vector<char> numbers;
bool cmp(char a,char b){return a>b;}
int main(){
    freopen("./number.in","r+",stdin);
    freopen("./number.out","w+",stdout);
    cin>>s;
    for(auto x:s){if(isdigit(x)){numbers.push_back(x);}}
    sort(numbers.begin(),numbers.end(),cmp);
    for(auto x:numbers){cout<<x;};cout<<endl;
    fclose(stdin);
    fclose(stdout);return 0;
}