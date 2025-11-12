#include<bits/stdc++.h>
using namespace std;
int const N=1e5+7;
struct node{
	int a,b,c;
}num[N];
int A=1;
int m[7];
long long ans=0;
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	for(int i=1;;i++) cout<<i<<" "<<i*3<<" ";
	return 0;
}
