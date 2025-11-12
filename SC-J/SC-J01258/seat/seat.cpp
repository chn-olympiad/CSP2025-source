#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
int a,b,m,p;
int score[100];
int num[100];
cin>>a>>b;
for(int i=0;i<a*b;i++){
	cin>>score[i];
}
p = score[0];
sort(score,score+(a*b),cmp);
for(int j=0;j<a*b;j++){
	if(p == score[j]){
		m = j+1;
	}
}
if(m == b){
	cout<<1<<" "<<b; 
}else if(m % b ==0 && (m/b)%2==0){
	cout<<m/b<<" "<< 1;
}else if(m % b ==0 && (m/b)%2==1){
	cout<<m/b<<" "<< 4;
}else{
	cout<<(m/b)+1<<m%b;
}








return 0;	
}