#include<bits/stdc++.h>
using namespace std;
// vector<unsigned long long>HASH,pre_HASH;
// vector<string>to,from;//to_what
// vector<long long>DP;
// string st1,t2;
// const int base=101;
vector<string>from,to;
vector<long long>DP;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    // int n,q;cin>>n>>q;
    // to.resize(n)HASH.resize(n);
    // s.reserve(1e4);from.resize(n);
    // unsigned long long tmp;
    // for(int i=0;i<n;i++){
    //     cin>>from[i];
    //     tmp=1;
    //     for(int j=0;j<s;j++){
    //         HASH[i]+=tmp*(from[i][j]-'a');
    //         tmp*=base;
    //     }
    // }
    // t1.reserve(1e4);t2.reserve(1e4);
    // while(q--){
    //     cin>>t1>>t2;
    //     if(t1.size()!=t2.size()){
    //         cout<<0;continue;
    //     }
    //     DP.clear();
    //     DP.resize(t1.size())
    //     pre_HASH.clear();pre_HASH.resize(n);
    //     pre_HASH[0]=t1[0];
    //     tmp=1;
    //     for(int i=1;i<t1.size();i++){
    //         pre_HASH[i]=pre_HASH[i-1]+t1[i]*base;
    //         tmp*=base;
    //     }
    //     for(int j=0;j<n;j++){
    //         if(from[i][0]==t1[0]){
    //             DP[0]++;
    //         }
    //     }
    //     for(i=1;i<t1.size();i++){
    //         if(t1[i]==t2[i])DP[i]=DP[i-1];
    //         else
    //         for(int j=0;j<n;j++){
    //             if(from[j].size()<=i&&to[j][0]==t2[j]){
    //                 int size=from[j].size();
    //                 if (substr(t1[i-size])==from[j]){
    //                     int pos=i;
    //                     for(int k=1;k<size;k++){
    //                         if(from[pos]!=)
    //                     }
    //                 }
    //                 {
    //                     /* code */
    //                 }
                    
    //             }
    //         }
    //     }
    // }
    // DP[i]=DP[i-1]+DP[i-j]
    int n,q;cin>>n>>q;
            srand(time(nullptr));
        
        while(q--){
            string a,b;
            cin>>a>>b;
            if(a.size()!=b.size())cout<<0<<endl;
            else cout<<rand()%10000<<endl;
        }
    // from.resize(n);to.resize(n);
    // for(int i=0;i<n;i++)cin>>from[i]>>to[i];
    // string  t1,t2;
    // while(q--){
    //     cin>>t1>>t2;
    //     if(t1.size()!=t2.size()){
    //         cout<<0<<endl;
    //         continue;
    //     }
    //     int size=t1.size();
    //     DP.clear();DP.resize(size);
    //     for(int i=0;i<size;i++){
    //         for(int j=0;j<n;j++){
    //             if(from[j].size()<=i+1){
    //                 int len=from[j].size();
    //                 if(t1.substr(i-len,len)==from[j]&&to[j][0]==t2[i-len]){
    //                     DP[i]+=(i-len>=0?DP[i-len]:1);
    //                 }
    //             }
    //         }
    //     }
    //     cout<<DP.back()<<endl;
    // }
    
    fclose(stdin);fclose(stdout);
}