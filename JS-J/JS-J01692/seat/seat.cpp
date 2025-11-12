#include <bits/stdc++.h>
using namespace std;
int seat[1005] = {};
int tseat[12][12];
int main(){
    int a,b;
    cin>>a>>b;
    for(int i = 1;i <= a*b;i++){
        cin>>seat[i];
    }
    int k = seat[1];
    sort(seat+1,seat+1+a*b);
    int z;
    for(int i = 1;i <= a*b;i++){
            //cout<<seat[i]<<endl;
        if(seat[i] == k) z=i;

    }
    z = a*b+1-z;
    //cout<<z;
    int q,r,c;
/*   for(int i = 1;i <= a;i++){
        if(b*i < z and b*(i+1) >= z){
            q = i+1;
            r = z - b*i;

            if(i%2 == 1) c = r;
            else c = b-r;
            break;
        }
    }

    cout<<q<<' '<<c;
}*/
    int bl = 1;
    for(int i = 1;i <= a;i++){

        if(i % 2 == 0){
            for(int j = b;j >= 1;j--){
                tseat[i][j] = bl;

bl++;
            }
        }
        else{
            for(int j = 1;j <= b;j++){
                tseat[i][j] = bl;


bl++;
            }
        }


    }
    for(int i = 1;i <= a;i++){
        for(int j = 1;j <= b;j++){
            if(tseat[i][j] == z) cout<<i<<' '<<j;
        }
    }

    return 0;
}
