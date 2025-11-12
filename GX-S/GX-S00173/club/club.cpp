#include<bits/stdc++.h>
using namespace std;

long long n,r,,t,shuchu[1000000],d1,d2,d3, c12,c13,c23,a,b,c;
int cmp(int x,int y){
    if(x>y){
        
        return x;
    }
    else return y;
}
int min(int x,int y,int z){
    if(x<y&&x<=z){
        
        return x;
    }
    else if(y<=x&&y<z){
        
        return y;
    }
    else if(z<x&&z<=y){
        
        return z;
    }

    else 
    
    return x;
}




int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;

for(int i=1;i<=t;i++){
    n=0;
    cin>>n;
for(int j=i;j<=n;j++){
int d1,d2,d3
    cin>>d1>>d2>>d3;
    



c12[j]=abs(d1-d2);
c13[j]=abs(d1-d3);
c23[j]=abs(d2-d3);
if(cmp(d1,d2)==d1){if(min(d1,d2,d3)==d3){a++;shuchu[t]+=d1;}}
if(cmp(d2,d3)==d2){if(min(d1,d2,d3)==d1){b++;shuchu[t]+=d2;}}
if(cmp(d3,d1)==d3){if(min(d1,d2,d3)==d2){c++;shuchu[t]+=d3;}}

int jishu=min(c12,c13,c23);
if(a>n/2||b>n/2||c>n/2){
    if(a>n/2){
if(cmp(c12,c13)==c12){
    --a;shuchu[t]=shuchu[t]+d3-d1;
    ++c;
}
else --a;++b;shuchu[t]=shuchu[t]+d2-d1;
    }
       if(b>n/2){
if(cmp(c12,c23)==c12){
    ++c;shuchu[t]=shuchu[t]-d2+d3;
    --b;
}
else --b;++a;shuchu[t]=shuchu[t]+d1-d2;
    }
       if(c>n/2){
if(cmp(c23,c13)==c23){
    --c;shuchu[t]=shuchu[t]+d1-d3;
    ++a;
}
else ++b;--c;shuchu[t]=shuchu[t]+d2-d3;
    }
}


}



}

for(int i=1;i<=t;i++){
    cout<<shuchu[i]<<endl;
}


  return 0;
}