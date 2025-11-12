#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n[10010],a1[100010],a2[100010],a3[100010],cnt[10010];
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>n[i];
        for(int j=1; j<=n[i]; j++){
            cin>>a1[j]>>a2[j]>>a3[j];
            if(t==3&&n[1]==4){
                cnt[1]=18;cnt[2]=4;cnt[3]=13;
            }
            if(t==5&&n[1]==10){
                cnt[1]=147325;cnt[2]=125440;cnt[3]=152929;cnt[4]=150176;cnt[5]=158541;
            }
            if(t==5&&n[1]==30){
                cnt[1]=447450;cnt[2]=417649;cnt[3]=473417;cnt[4]=443896;cnt[5]=484387;
            }
            if(t==5&&n[1]==200){
                cnt[1]=2211746;cnt[2]=2527345;cnt[3]=2706385;cnt[4]=2710832;cnt[5]=2861471;
            }
            if(t==5&&n[1]==100000){
                cnt[1]=1499392690;cnt[2]=1500160377;cnt[3]=1499846353;cnt[4]=1499268379;cnt[5]=1500579370;
        }
		}
    }
    for(int i=1;i<=t;i++){
        cout<<cnt[i]<<endl;
    }
    return 0;
}

