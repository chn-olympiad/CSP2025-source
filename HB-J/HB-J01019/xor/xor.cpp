#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
ULL n,s,ans,cnt;
const ULL N=1e6;
ULL a[N],b[N];
string s1,s2,s3;
ULL sum;
bool flag=false;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>s;
    for(ULL i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n;j++){
            if(j<=i){
                while(b[j]){

                    s1.push_back(char(b[j]%=2+'0'));
                    b[j]/=2;
                }
                while(sum){
                    s2.push_back(char(sum%=2+'0'));
                    sum/=2;
                }
                int len=max(s1.length(),s2.length());
                for(int k=0;k<len;k++){
                    if(s1[k]==s2[k]){
                        s3.push_back('1');
                    }
                    else s3.push_back('0');
                }
                for(int k=0;k<s3.length();k++){
                    sum+=int(s3[k]-'0')*pow(2,k);
                }
                if(sum!=s){
                    s1=' ';
                    s2=' ';
                    s3=' ';
                    sum=0;
                    continue;
                }
                cnt++;
            }
            else{
                 while(b[j]){

                    s1.push_back(char(b[j]%=2+'0'));
                    b[j]/=2;
                }
                while(sum){
                    s2.push_back(char(sum%=2+'0'));
                    sum/=2;
                }
                int len=max(s1.length(),s2.length());
                for(int k=0;k<len;k++){
                    if(s1[k]==s2[k]){
                        s3.push_back('1');
                    }
                    else s3.push_back('0');
                }
                for(int k=0;k<s3.length();k++){
                    sum+=(int(s3[k]-'0')*pow(2,k));
                }
                if(sum!=s){
                    s1=' ';
                    s2=' ';
                    s3=' ';
                    sum=0;
                    continue;
                }
                cnt++;
            }
            }
        }
        cout<<cnt;
    return 0;
}


