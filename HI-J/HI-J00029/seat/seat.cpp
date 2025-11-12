#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,n1=1,m1=1,score[1000],me;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>score[i]; 
	} 
	me=score[0];
	for(int i=0;i<n*m;i++){
		for(int y=0;y<n*m-i;y++){
			if(score[y]<score[y-1]){
				int temp=score[y];
				score[y]=score[y-1];
				score[y-1]=temp;
		}
	}}
	for(int i=n*m-1;i>=0;i--){
		if(score[i]==me) cout<<m1<<' '<<n1; else if(m1%2!=0 ) n1++; else if(m1%2==0) n1--;
		if (n1==n+1 and m1%2!=0) {
			n1=n;
			m1++;
		}
		else if(n1==0 and m1%2==0){
			n1=1;
			m1++;
		}
	} 
	return 0;
} 
