#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int student=n*m;
int grade[n*m];
for(int i=0;i<n*m;i++){
    cin>>grade[i];
}
int c=grade[0];
for(int i=0;i<student;i++){
    for(int o=0;o<student-1;o++){
        if(grade[o]<grade[o+1]){
            swap(grade[o],grade[o+1]);
        }
    }
}
int index;
for(int i=0;i<student;i++){
    if(grade[i]==c){
        index=i;
        break;
    }
}
index++;
int number1=index%n;
int number2=index/n;
if(number1!=0){
    number2++;
}
if(number1==0){
    number1=n;
}
int r;
if(number2%2==0){
    r=n-number1;
    r++;
}else{
r=number1;
}
cout<<number2<<" "<<r;
return 0;
}
