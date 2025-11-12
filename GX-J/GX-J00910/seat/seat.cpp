#include<bits/stdc++.h>
using namespace std;
int n,m,s[101],r,g,k=0;
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);

cin>>n>>m;
for(int i=0;i<m*n;i++){
    cin>>s[i];
}
r=s[0];
for(int i=0;i<n*m;i++){
        for(int j=0;j<n*m;j++){
            if(s[j]<s[i]){
                    swap(s[j],s[i]);
            }

        }
}
for(int i=0;i<n*m;i++){
    k++;
    if(s[i]==r){
        break;
    }
}

int x=k,y=0;
while(x>=0){
    x-=m;
    y++;
}

if(k<=m){
    cout<<1<<" "<<k;
}
else if(y%2==0){
    cout<<y<<" "<<m+1-k%m;
}
else{
    cout<<y<<" "<<k%m;
}




return 0;

}
