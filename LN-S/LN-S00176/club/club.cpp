#include<bits/stdc++.h>
using namespace std;
struct mm{
int a;
int b;
int c;
int hm;
}club[30];
bool cmp(mm a,mm b){
    return a.a>b.a;
}
void ceshi(){
int n,i,cnt=0;
cin>>n;i=n;
while(n--)
    cin>>club[n].a>>club[n].b>>club[n].c;
sort(club,club+n,cmp);
for(int i=0;i<n/2;i++)
    cnt+=club[i];
cout<<cnt<<endl;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int n;
cin>>n;
while(n--){
ceshi();
}
return 0;
}
