#include<bits/stdc++.h>
#include<iostream>
#define N 10001

using namespace std;

int i,j=0;
string str1[N][N];
string str2[N][N];
long m,n,q=0;
string t2[N][N];
string t3[N][N];
int cnt[N]={0};

int main(){

freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
fclose(stdin);
fclose(stdout);

cin>>n>>q;

for(i=1;i<=n;i++){
    cin>>str1[i][1]>>str2[i][2];
    if(sizeof(str1)!=sizeof(str2)){
        return 0;
    }
}
for(j=1;j<=q;j++){
    cin>>t2[j][1]>>t2[j][2];
}
for(i=1;i<=n;i++){
    for(j=1;i<=q;j++){
        if(str1[i][j]==t2[i][j]||str2[i][j]==t3[i][j]){
            cnt[j]++;
        }
    }
}

for(i=1;i<=q;i++){
    cout<<cnt[j]<<endl;
}
return 0;


}
