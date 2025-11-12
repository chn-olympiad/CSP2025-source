#include<iostream>

int main(){
int a,b,xr;
std::cin>>a>>b>>xr;
int j=(a*b)-1;
int o=0;
int n[a*b];
for(int i=0;i<=j;i++){
std::cin>>n[i];
if(n[i]>xr){
o++;
}
}
int q=o%2;
int u=o/2;
std::cout<<q<<" "<<u<<std::endl;
return 0;

}
