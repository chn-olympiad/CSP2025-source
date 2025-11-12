#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n;
    int a[n];
    string s[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        while(a[i]!=0){
            s[i]=s[i]+char(a[i]%2);
            a[i]=a[i]/2;

        }
    }

    for(int i=0;i<n;i++){
            int e=0;
            string ans=s[0],x;
        for(int j=0;j<s[i].size();j++){
            if(ans[j]==0&&s[i][j]==0){
                x=x+'0';
            }else{
                x=x='1';
            }
            ans=x;
            int y=1,z=0;
            for(int j=0;j<ans.size();j++){
                z=z+int(ans[j])*y;
                y=y*2;
            }
            if(z==2){
                cout<<e<<' '<<i;
                e=i;
                ans=s[i+1];
            }

        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
