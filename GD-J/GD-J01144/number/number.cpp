#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inn;
    ofstream outt;
    inn.open("number.in");
    outt.open("number.out");

    string input;
    inn >> input;
    vector<int> num;
    int anslen=0,ans=0;
    int len=input.length();
    for(int i=0;i<len;i++)
    {
        char now;
        now=input[i];
        if(now >='0' && now <='9')
        {
            num.push_back(now-'0');
            anslen++;
        }
    }
    sort(num.begin(),num.end());
    for(int i=anslen-1;i>=0;i--)
    {
        outt<<num[i];
    }
    inn.close();
    outt.close();
    return 0;
}