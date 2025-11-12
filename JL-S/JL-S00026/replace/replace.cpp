#include<bits/stdc++.h>
using namespace std;
unsigned long long n,q;
string a[200005],b[200005];
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
scanf("%lld%lld",&n,&q);

for(int i=0;i<n;i++){
cin>>a[i]>>b[i];
}
while(q--){
        int cnt=0;
        unsigned long ans=0;
string a1,b1,a2;
cin>>a1>>b1;
if(a1.size()!=b1.size()){printf("0\n");continue;}
for(int i=0;i<a1.size();i++){
        if(a1[i]!=b1[i])cnt++;
        while(a1[i]!=b1[i])i++;
        if(cnt==2)break;
        }

        if(cnt==1)
for(int j=0;j<n;j++)
for(int i=0;i+a[j].size()<=a1.size();i++){

  if(a1[i]==a[j][0]&&a[j].size()+i<=a1.size()){
        a2=a1;
        a2[i]=b[j][0];
        int pos=i;
    for(int k=1;k<a[j].size();k++){
        if(a2[i+k]==a[j][k])a2[k+i]=b[j][k];
        else {a2='A';break;}
    }
    if(a2==b1)ans++;

  }

}
printf("%lld",ans);
ans=0;
}
    return 0;
}
//

