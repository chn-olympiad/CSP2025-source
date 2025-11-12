#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string aaa;
    cin>>aaa;
    int answer[15]={0};
    int maxnumber=0;
    for(int i=0;i<aaa.size();i++){
        switch(aaa[i]){
            case '1':
                answer[1]++;
                maxnumber=max(1,maxnumber);
                break;
            case '2':
                answer[2]++;
                maxnumber=max(2,maxnumber);
                break;
            case '3':
                answer[3]++;
                maxnumber=max(3,maxnumber);
                break;
            case '4':
                answer[4]++;
                maxnumber=max(4,maxnumber);
                break;
            case '5':
                answer[5]++;
                maxnumber=max(5,maxnumber);
                break;
            case '6':
                answer[6]++;
                maxnumber=max(6,maxnumber);
                break;
            case '7':
                answer[7]++;
                maxnumber=max(7,maxnumber);
                break;
            case '8':
                answer[8]++;
                maxnumber=max(8,maxnumber);
                break;
            case '9':
                answer[9]++;
                maxnumber=max(9,maxnumber);
                break;
            case '0':
                answer[0]++;
                maxnumber=max(0,maxnumber);
                break;
            default:
                break;
        }
    }
    for(int i=maxnumber;i>=0;i--){
        if(answer[i]>0){
            while(answer[i]--){
                cout<<i;
            }
        }
    }
    return 0;
}
