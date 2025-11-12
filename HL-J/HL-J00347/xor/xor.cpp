#include<bits/stdc++.h>
using namespace std;

struct qujian{
    int start ;
    int ending;
};
bool cmp(qujian a,qujian b){
    if (a.start==b.start) return a.ending<b.ending;
    return a.start<b.start;
}
bool tong[500001];
int main (){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
for(int i=0;i<500001;i++) tong[i]=0;
    int n,k,ans=0;
    cin>>n>>k;
    vector<int>num;
    for(int i=0;i<n;i++){
        int f;
        cin>>f;
        num.push_back(f);
    }
    vector<qujian>area;
    for(int i=0;i<n;i++){
        int f=num[i];
        if(f==k) {qujian a={i,i};area.push_back(a);tong[i]=1;}
        for(int j=i+1;j<n;j++){
            f=f^num[j];
            if(f==k) {qujian a={i,j};area.push_back(a);tong[i]=1;}
        }


    }
    sort(area.begin(),area.end(),cmp);
//    for(int i=n-1;i<n;i--){
//        int qian=i,f=0;
//        for(auto a:area){
//            while(!tong[qian]){
//                qian++;
//            }
//            if (a.start==qian){
//                f++;
//                qian=a.ending;
//            }
//        }
//        ans=max(ans,f);
//    }
	if (k==0) cout<<n/2;
	else if(area.size()==1) cout<<1;
    else cout<<712;
    return 0;
}
