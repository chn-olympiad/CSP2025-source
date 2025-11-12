#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    scanf("%d%d",&n,&m);
    vector<int>grade;
    for(int i=0;i<n*m;i++){
        scanf("%d",&r);
        grade.push_back(r);
    }
    r=grade[0];
    sort(grade.begin(),grade.end());
    int number=0;
    while(grade[number]!=r){
        number++;
    }
    number=grade.size()-number;
    printf("%d %d",(number+(n-1))/n,((number+(n-1))/n%2!=0?(number%n==0?n:number%n):(number%n==0?1:n+1-number%n)));
    return 0;
}
