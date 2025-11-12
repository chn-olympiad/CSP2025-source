#include<bits/stdc++.h>
using namespace std;
int people[120];
bool mycmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>people[i];
    }
    int rsc=people[0],pos;
    sort(people,people+n*m,mycmp);
    for(int i=0;i<n*m;i++){
        if(people[i]==rsc){
            pos=i;
            break;
        }
    }
    int ans=0;
    if((pos/n)%2==0){
        ans=pos%n+1;
    }else{
        ans=n-pos%n;
    }
    cout<<pos/n+1<<" "<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
