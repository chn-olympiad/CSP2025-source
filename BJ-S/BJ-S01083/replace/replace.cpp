#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string a[N][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    while(q--){
        string s1,s2,s3;
        int sum=0;
        cin>>s1>>s2;

        s3=s1;
        for(int i=1;i<=n;i++){
            int l=0;
            int rrr=s1.find(a[i][0],l);
            while(rrr!=-1){
                int len=a[i][0].size();
                for(int j=0;j<len;j++){
                    s3[rrr+j]=a[i][1][j];
                }
                if(s3==s2){
                    sum++;
                }
                l=rrr+len;
                rrr=s1.find(a[i][0],l);
                s3=s1;
            }
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
