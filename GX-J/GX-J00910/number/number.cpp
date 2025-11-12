#include<bits/stdc++.h>
using namespace std;
string s;
int n=255,a[1001];
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);

cin>>s;

for(int i=0;i<n;i++){
    if(s[i]-'0'>=0&&s[i]-'0'<=9){
            a[1001]=s[i]-'0';
    }
}

for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[j]<a[i]){
                    swap(s[j],s[i]);
            }

        }
}
for(int i=0;i<n;i++){
    cout<<a[i];
}

return 0;

}
