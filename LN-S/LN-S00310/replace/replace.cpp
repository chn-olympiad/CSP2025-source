#include <bits/stdc++.h>

using namespace std;
const int N=200001;
string s1[N],s2[N];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q){
        int sum=0;
        string a1,a2,s;
        cin>>a1>>a2;
        for(int i=0;i<n;i++){
            int l1=s1[i].length(),l2=a1.length();
            for(int j=0;j<l2;j++){
                s=a1;
                for(int t=0;t<l1;t++){
                    if(s[j+t]==s1[i][t]){
                        s[j+t]=s2[i][t];
                    }
                    else{
                        s=a1;
                        break;
                    }
                    if(s==a2&&t==l1-1)sum++;
                }
            }
        }
        cout<<sum<<endl;
        q--;
    }
    return 0;
}
