#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int score[n*m+5];
	int aim;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
		if(i==1) aim=score[i];
	}
	sort(score+1,score+n*m+1,cmp);
	int order;
	for(int i=1;i<=n*m;i++){
		if(score[i]==aim){
			order=i;
			break;
		}
	}
	int h,l;
	if(order%n==0) l=order/n;
	else l=order/n+1;
	if(l%2==1){
		if(order%n==0) h=n;
		else h=order%n;
	}
	else{
		if(order%n==0) h=1;
		else h=n-order%n+1; 
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
