#include<bits/stdc++.h>
using namespace std;
int mark[105];
bool comp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,R,cnt=0,c,r;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a*b;i++)
		scanf("%d",&mark[i]);
	R=mark[1];
	sort(mark+1,mark+a*b+1,comp);
	for(int i=1;i<=a*b;i++){
		cnt++;
		if(mark[i]==R)
			break;
	}
	c=(cnt-1)/a+1;
	if(c%2==0){
		r=a-(cnt-1)%a;
	}
	else{
		r=(cnt-1)%a+1;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
