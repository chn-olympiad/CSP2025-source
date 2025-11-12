#include<bits/stdc++.h>
using namespace std;
int score[120];
int n,m,R,f=1,c=1,r=1;
bool flag;
bool cmp(int c,int b) {
	return c>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a=n*m;
	for(int i=1;i<=a;i++){
		cin>>score[i];
	}
	R=score[1];
	sort(score+1,score+1+a,cmp);
	while(f<a){
		flag=false;
		if(c%2==1){
			r++;
			f++;
			if(r==n) flag=true;
		}else{
			r--;
			f++;
			if(r==1) flag=true;
		}
		if(score[f]==R) break;
		if(flag==true) c++;
	}
	cout<<c<<" "<<r;
	return 0;
}
