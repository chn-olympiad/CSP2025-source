#include <bits/stdc++.h>
using namespace std;
int t;
int Member[10][100050][3];
int dp[10][100050];
int tempN[5];
int curDataOfCLub[5][3];
bool ifChoose[10][100050][3];
int main() {
freopen("club3.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;

for(int i = 0;i<t;i++){
    cin>>tempN[i];

}
for(int i = 0 ; i<t;i++){
        int mmm = tempN[i];

for(int j = 0 ; j<mmm;j++){
        cin>> Member[i][j][0];
        cin>> Member[i][j][1];
        cin>> Member[i][j][2];

    }
}

for(int i = 0;i<t;i++){

        for(int temp =0;temp<100050;temp++) dp[i][temp] = 0 ;//initialization

    for(int j = 0;j<tempN[i];j++){//choose student
            for(int c = 0 ; c<3;c++){//choose club

    int tempCom = dp[i][j];
    dp[i][j] = max(dp[i][j],dp[i][j-1]+Member[i][j][c]);

    if(curDataOfCLub[i][c] >= tempN[i]/2 && dp[i][j] != tempCom){
            int tempAmount = 0;

        for(int tempA = 0;tempA<j;tempA++){
                int tempRecord;
                int tempSign = tempAmount;

                if(ifChoose[i][tempA][c]==true){tempAmount = min(Member[i][tempA][c],tempAmount);}

                if(tempAmount !=tempSign){
                    tempRecord = tempA;
                }

            if(Member[i][tempRecord][c]<Member[i][j][c]&&ifChoose[i][tempRecord][c]==true){
                ifChoose[i][tempRecord][c]= false;
                dp[i][j]=dp[i][j] - Member[i][tempRecord][c];
            }
        }
    }

    if(dp[i][j] != tempCom){
        if(c-1 >=-1) {
        curDataOfCLub[i][c-1]--;
        ifChoose[i][j][c-1] = false;}
        ifChoose[i][j][c]= true;
        curDataOfCLub[i][c]++;
    }
    }

    }
for(int tempp = 0;tempp<tempN[i];tempp++){
    cout<<Member[i][tempp][0]<<' '<<Member[i][tempp][1]<<' '<<Member[i][tempp][2]<<endl;
    cout<<ifChoose[i][tempp][0]<<' '<<ifChoose[i][tempp][1]<<' '<<ifChoose[i][tempp][2]<<endl<<"---------------"<<endl;
}
    cout<<dp[i][tempN[i]-1]<<1145141919810<<endl;
}

return 0;
}

