#include<iostream>
#include<cstdio>
using namespace std;
int n;long long k,s[100005];
int cnt;
bool b[100005];
//string to_er(long long x){
//    int a[10005];
//    long long cnt=0;
//    while(1){
//        if(x==0)  break;
//        a[++cnt]=x%2;
//        x/=2;
//    }
//    string ans="";
//    for(int i=cnt;i>=1;i--){
//        ans+=(a[i]+'0');
//    }
//    return ans;
//}
//string xor(string a,string b){
//    if(a.size()<b.size()){
//        for(int i=1;i<=b.size()-a.size();i++){
//            a='0'+a;
//        }
//    }else if(a.size()>b.size()){
//        for(int i=1;i<=a.size()-b.size();i++){
//            b='0'+b;
//        }
//    }
//    string ans="";
//    for(int i=0;i<a.size();i++){
//        if(a[i]==b[i]){
//            ans+="0";
//        }else ans+="1";
//    }
//    return ans;
//}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
//    for(int l=1;l<=n;l++){
//        for(int r=l;r<=n;r++){
//            int jz=s[l];
////            if(jz==0){
////                cout<<(jz^3)<<endl;
////            }
//            for(int i=l+1;i<=r;i++){
//                jz=(jz^s[i]);
//            }
//            if(jz==k){
//                cnt++;
//                for(int i=l;i<=r;i++){
//                    if(b[i]==true)
//                }
//            }
//        }
//    }
    for(int len=1;len<=n;len++){
        for(int l=1;l<=n-len+1;l++){
            int r=l+len-1;
            int jz=s[l];
            for(int i=l+1;i<=r;i++){
                jz=(jz^s[i]);
            }
            if(jz==k){
                for(int i=l;i<=r;i++){
//                    cout<<i<<' ';
                    if(b[i]==true){
                        cnt--;
                        break;
                    }
                    b[i]=true;
                }
                cnt++;
//                cout<<endl<<l<<' '<<r<<' '<<cnt<<endl;
            }
        }
    }
    cout<<cnt;
    return 0;
}
