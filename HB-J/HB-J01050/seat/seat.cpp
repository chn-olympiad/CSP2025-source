#include<bits/stdc++.h>
using namespace std;
int n,m,rchenji;
vector<int> students;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat","r",stdin);
    freopen("seat","w",stdout);
    cin>>n>>m;
    students.resize(n*m);
    for(int i=0;i<n*m;i++){
        cin>>students[i];
    }
    rchenji=students[0];
    sort(students.begin(),students.end(),cmp);
    int seat[n][m],nowstudentindex=0;
    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                seat[j][i]=students[nowstudentindex];
                nowstudentindex++;
            }
        }
        if(i%2==1){
            for(int j=n-1;j>=0;j--){
                seat[j][i]=students[nowstudentindex];
                nowstudentindex++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(seat[i][j]==rchenji)cout<<j+1<<" "<<i+1;
        }
    }
    return 0;
}
