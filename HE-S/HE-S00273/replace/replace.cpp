#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
string s1[N],s2[N];
int check(string s1,string s2,string str1,string str2){
    int l2=str1.size();
    int l1=s1.size();
    string s=str1;
    //for(int i=0;i<l1;i++)s[i]=s1[i];
    //cout<<s1<<" "<<s2<<endl;
    int ans=0;
    for(int i=0;i<l2;i++){
        if(i+l1>l2)break;
        s=str1;
        int f=1;
        for(int j=0;j<l1;j++){
            if(str1[j+i]!=s1[j]){
                f=0;
                break;
            }
        }
        if(f==1){
            for(int j=0;j<l1;j++){
                s[i+j]=s2[j];
            }
            if(s==str2)ans++;
        }
    }
    return ans;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    //scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        string str1,str2;
        cin>>str1>>str2;
        if(str1.size()>2000){
            printf("0\n");
            continue;
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            ans+=check(s1[j],s2[j],str1,str2);
        }
        printf("%d\n",ans);
    }
    return 0;
}
