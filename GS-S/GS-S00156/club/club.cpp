#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int student[n][3];
        for(int i=0;i<n;i++){
            cin>>student[i][0]>>student[i][1]>>student[i][2];
        }
        int ans=0,choice[n]={};
        while(choice[n-1]<=2){
            int res=0,a=0,b=0,c=0;
            for(int i=0;i<n;i++){
                res+=student[i][choice[i]];
                if(choice[i]==0)a++;
                if(choice[i]==1)b++;
                if(choice[i]==2)c++;
            }
            if(a+b+c>=2*max(a,max(b,c)))ans=max(ans,res);
            choice[0]++;
            for(int i=0;i<n-1;i++){
                if(choice[i]==3){
                    choice[i]=0;
                    choice[i+1]++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
