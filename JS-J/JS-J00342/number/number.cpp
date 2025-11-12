#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
ifstream fin("number.in");
ofstream fout("number.out");
string s1,s2;
int n,m;
int main(){
    fin>>s1;
    int n=s1.size();
    for(int i=0;i<n;i++)
        if(s1[i]>='0'&&s1[i]<='9')
            s2+=s1[i],m++;
    sort(s2.begin(),s2.end());
    for(int i=m-1;i>=0;i--)fout<<s2[i];
}

