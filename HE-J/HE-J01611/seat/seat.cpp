#include <bits/stdc++.h>
using namespace std;
int cnt[10];
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,d,e,n,m;
	cin>>a>>b;
	int c=a*b;
	int A[c];
	for(int i=0;i<c;i++){
		if(i==0){
			cin>>e;
			A[0]=e;
		}else{
			cin>>A[i];
		}
		
	}sort(A+0,A+c,cmp);
	for(int i=0;i<c;i++){
		if(A[i]==e){
			d=i;
		}
}	if((d%b+1)==0 && d%(b*2)==b*2-1){
		m=d/b;
	}else if(d%(b*2)==b){
		m=d/b+1;
	}
	else{
		m=d/b+1;
	}
		
		
		int p=(d-(b*(m-1)))%b;
	if(m%2==1){
		n=(d+1)%b;
	}else{
		n=abs(p-b);
	}
	cout<<m<<" "<<n;
	return 0;
}//shift;
//¿××Óhelp 
