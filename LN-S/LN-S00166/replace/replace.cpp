#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[6000000],s2[6000000];
int main()
{
    freopen("replace1.in","r",stdin);
    freopen("replace1.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>s1[i];
        cin>>s2[i];
        int length=0,j=0;
        printf("%c\n",s1[i][0]);
        while('a'<=s1[i][j]<='z') length++,j++;
        printf("%d\n",length);
        //for(int i=1;i<=sizeof(s1[i]);i++);
    }
    return 0;
}
