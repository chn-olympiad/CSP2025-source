#include <bits/stdc++.h>
using namespace std; 
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout); 
    int n,m;
    cin>>n>>m;
    int cnt=n*m,sco[cnt+3];
    for(int i=0;i<cnt;i++)cin>>sco[i];
    int im=sco[0]; 
    sort(sco,sco+cnt);
    int j=n*m-1,dn=0,dm=0;
    if(sco[j]==im)cout<<"1 1";
    else{
        j--;
    while(1){
        if(dm%2==0){
            if(dn<n-1)dn++;
            else  dm++;
        }
        else{
            if(dm%2==1){
                if(dn>0)dn--;
                else dm++;
            }
        }
        if(sco[j]==im)break;
        j--;
    }
    }
    cout<<dm+1<<" "<<dn+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
