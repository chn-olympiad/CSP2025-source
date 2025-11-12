#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <map>
using namespace std;
char s[1000005];set<int> a;
vector<int>a2;map<int,int>m;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++)if(s[i]>='0'&&s[i]<='9'){a.insert(s[i]-48);m[s[i]-48]++;}
    for(auto i:a) a2.push_back(i);
    for(int i=a2.size()-1;i>=0;i--)
        while(m[a2[i]]--)printf("%d",a2[i]);
    return 0;
}
