#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for (int i = 0;i < t;i++)
    {
        int n,q[100000][3],total = 0,group0 = 0,group1 = 0,group2 = 0,alter[100000][3];
        cin >> n;
        int limit = n/2;
        for(int j = 0;j < n;j++)
        {
            for(int k = 0;k <= 2;k++)
            {
                cin >> q[j][k];
            }
            if(q[j][0] >= q[j][1] && q[j][0] >= q[j][2]){
                group0++;
                alter[j][0] = -1;
                alter[j][1] = q[j][0] - q[j][1];
                alter[j][2] = q[j][0] - q[j][2];
                total += q[j][0];
            }
            else if(q[j][1] >= q[j][0] && q[j][1] >= q[j][2]){
                group1++;
                alter[j][1] = -1;
                alter[j][0] = q[j][1] - q[j][0];
                alter[j][2] = q[j][1] - q[j][2];
                total += q[j][1];
            }
            else{
                group2++;
                alter[j][2] = -1;
                alter[j][0] = q[j][2] - q[j][0];
                alter[j][1] = q[j][2] - q[j][1];
                total += q[j][2];
            }
        }
        if(group0 <= limit&&group1 <= limit&&group2 <= limit)
            cout << total << endl;
        else{
            while (group0 > limit){
                int pos = 100000;
                int ind[2];
                ind[0] = 0;ind[1] = 0;
                for(int iga = 0;iga < n;iga++){
                    if (alter[iga][0] != -1) continue;
                    if (alter[iga][1]<pos) {pos = alter[iga][1];ind[0] = iga;ind[1] = 1;}
                    if (alter[iga][2]<pos) {pos = alter[iga][2];ind[0] = iga;ind[1] = 2;}
                }
                group0--;
                total -= pos;
                alter[ind[0]][0] = -2;
            }
            while (group1 > limit){
                int pos = 100000;
                int ind[2];
                ind[0] = 0;ind[1] = 0;
                for(int iga = 0;iga < n;iga++){
                    if (alter[iga][1] != -1) continue;
                    if (alter[iga][0]<pos) {pos = alter[iga][0];ind[0] = iga;ind[1] = 0;}
                    if (alter[iga][2]<pos) {pos = alter[iga][2];ind[0] = iga;ind[1] = 2;}
                }
                group1--;
                total -= pos;
                alter[ind[0]][1] = -2;
            }
            while (group2 > limit){
                int pos = 100000;
                int ind[2];
                ind[0] = 0;ind[1] = 0;
                for(int iga = 0;iga < n;iga++){
                    if (alter[iga][2] != -1) continue;
                    if (alter[iga][0]<pos) {pos = alter[iga][0];ind[0] = iga;ind[1] = 0;}
                    if (alter[iga][1]<pos) {pos = alter[iga][1];ind[0] = iga;ind[1] = 1;}
                }
                group2--;
                total -= pos;
                alter[ind[0]][2] = -2;
            }
            cout << total << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

