#include<bits/stdc++.h>
using namespace std;
int score[110];
int n,m,l=1;
int r;
int hang=1,lie=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;	
	l=n*m;
	for(int i=1;i<=l;i++){
		cin>>score[i];	
	}
	r=score[1];
	sort(score,score+l);
	if(n==1){
	    for(int i=1;i<=l;i++){
		if(score[i]==r){
			hang=1;
			lie=m-i;
		    }
		}
    }
	if(m==1){
		for(int i=1;i<=l;i++){
		if(score[i]==r){
			lie=1;
			hang=n-i+1;
		    }
		}
	}
	cout<<hang<<" "<<lie; 
	return 0;
}
