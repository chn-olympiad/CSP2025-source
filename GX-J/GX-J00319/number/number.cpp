#include <bits/stdc++.h>

using namespace std;

string s;
int a[1000010];
int ans;
bool cmp(int a,int b){
    return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
   cin>>s;
   for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[ans++]=s[i]-'0';
        }
   }
   sort(a,a+ans,cmp);
   for(int i=0;i<ans;i++){
        cout<<a[i];
   }
    return 0;
}
