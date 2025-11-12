#include<bits/stdc++.h>
using namespace std;
int a[100001];
int cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            int n=s[i]-'0';
            if(cnt==0){
                a[0]=n;
                cnt=1;
            }else{
                int i=0;
                while(n<a[i]){
                    i++;
                }
                cnt++;
                int ri=i;
                int r=a[i];
                while(i!=cnt){
                    i++;
                    int p=a[i];
                    a[i]=r;
                    r=p;
                }
                a[ri]=n;
            }
        }
    }
    for(int i=0;i<cnt;i++){
        cout<<a[i];
    }
    return 0;
}
