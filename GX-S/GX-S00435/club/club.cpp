#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
                    freopen("club.in","r",stdin);
                    freopen("club.out","w",stdout);
cin>>a;
while(a--){
cin>>b;
int c[100001][4],num=0,m[100001],d=0,f[4];
d=b/2;
for(int i=1;i<=b;i++){
cin>>c[i][1]>>c[i][2]>>c[i][3];
m[i]=c[i][1];
if(c[i][1]>c[i][2]&&c[i][1]>c[i][3]&&c[i][2]>=c[1][3]){
  if(f[1]+1<=d){
  m[i]=c[i][1];
  f[1]++;
  }else if(f[2]+1<=d){
  m[i]=c[i][2];
  f[2]++;
  }else{
  m[i]=c[i][3];
  f[3]++;
  }

}
if(c[i][1]>c[i][2]&&c[i][1]>c[i][3]&&c[i][2]<c[1][3]){
  if(f[1]+1<=d){
  m[i]=c[i][1];
  f[1]++;
  }else if(f[3]+1<=d){
  m[i]=c[i][3];
  f[3]++;
  }else{
  m[i]=c[i][2];
  f[2]++;
  }

}



if(c[i][2]>c[i][1]&&c[i][2]>c[i][3]&&c[i][1]>=c[i][3]){
if(f[2]+1<=d){
  m[i]=c[i][2];
  f[2]++;
  }else if(f[1]+1<=d){
  m[i]=c[i][1];
  f[1]++;
  }else{
  m[i]=c[i][3];
  f[3]++;
  }
}
if(c[i][2]>c[i][1]&&c[i][2]>c[i][3]&&c[i][1]<c[i][3]){
if(f[2]+1<=d){
  m[i]=c[i][2];
  f[2]++;
  }else if(f[3]+1<=d){
  m[i]=c[i][3];
  f[3]++;
  }else{
  m[i]=c[i][1];
  f[1]++;
  }
}


if(c[i][3]>c[i][2]&&c[i][3]>c[i][1]&&c[i][1]>=c[i][2]){
if(f[3]+1<=d){
  m[i]=c[i][3];
  f[3]++;
  }else if(f[1]+1<=d){
  m[i]=c[i][1];
  f[1]++;
  }else{
  m[i]=c[i][2];
  f[2]++;
  }
}
if(c[i][3]>c[i][2]&&c[i][3]>c[i][1]&&c[i][1]<c[i][2]){
if(f[3]+1<=d){
  m[i]=c[i][3];
  f[3]++;
  }else if(f[2]+1<=d){
  m[i]=c[i][2];
  f[2]++;
  }else{
  m[i]=c[i][1];
  f[1]++;
  }
}
}

for(int i=1;i<=b;i++){
num+=m[i];
}

cout<<num<<endl;

}
}
