#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int ln,col;
vector<int> score;
int LS;
int main() {
    // #1,2,3:AC
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>> ln >> col ;
    for(int i=1;i<=ln*col;i++){
        int a;
        cin>> a ;
        if(i==1){
            LS=a;
        }
        score.push_back(a);
    }
    sort(score.begin(),score.end(),cmp);
    int x=1,y=1;
    bool down=true;
    for(int i=0;i<score.size();i++){
        if(score[i]==LS){
            cout<< y <<" "<< x <<endl;
            break;
        }
        if(x==ln&&down){
            down=false;
            y++;
        }
        else if(x==1&&!down){
            down=true;
            y++;
        }
        else{
            if(down){
                x++;
            }
            else x--;
        }
    }

    return 0;
}