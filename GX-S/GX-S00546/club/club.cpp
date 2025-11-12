#include <iostream>
#include <fstream>

using namespace std;
int group;
ifstream infile;
ofstream outfile;
int n,a[100000][3],allEnjoy;
void pos(int j,int sum,int f1,int f2,int f3){
    if(j >= n)allEnjoy = max(allEnjoy,sum);
    else {
        if(f1 < n/2)pos(j+1,sum+a[j][0],f1+1,f2,f3);
        if(f2 < n/2)pos(j+1,sum+a[j][1],f1,f2+1,f3);
        if(f3 < n/2)pos(j+1,sum+a[j][2],f1,f2,f3+1);
    }
}
void init(){
    for(int groupIndex = 0;groupIndex<group;groupIndex++){

        n=0;
        infile >> n;
        allEnjoy = 0;
        for(int i = 0;i<n;i++){
            infile >> a[i][0] >> a[i][1] >> a[i][2];
        }
        //read
        pos(0,0,0,0,0);
        pos(1,0,0,0,0);
        pos(2,0,0,0,0);
        outfile << allEnjoy << endl;
    }
}
int main(){
    infile.open("club.in");
    outfile.open("club.out");
    infile >> group;
    init();

    return 0;
}