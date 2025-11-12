#include<bits/stdc++.h>
using namespace std;
int a,b;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	int d=a*b,c[d],sum=0;
	for(int i=0;i<d;i++){
		cin>>c[i];
	}
	int r_score=c[0];
	sort(c,c+d,cmp);
	for(int i=0;i<d;i++){
		if(c[i]==r_score){
			sum=i;
		}
	}
	if((sum/a)%2==0){
		cout<<(sum/a)+1<<" "<<(sum%a)+1; 
	}
	else if((sum/a)%2==1){
		cout<<(sum/a)+1<<" "<<b-(sum%a);
	}
	return 0;
} 
