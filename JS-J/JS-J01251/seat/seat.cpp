#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,s,c,i=0,j=1,k,score[108],t[108]={0},d=1;
	cin>>m>>n;
	for(s=1;s<=m*n;s++){
		cin>>score[s];
		t[score[s]]++;
		if(s==1){
			k=score[s];
		}
	}
	s=0;
	for(c=100;c>=1;c--){
		if(t[c]){
			score[++s]=c;
		}
	}
	for(s=1;s<=m*n;s++){
		if(d==1){
			i++;
			if(i==m){
				d=2;
			}
		}else if(d==2){
			j++,d=3;
		}else if(d==3){
			i--;
			if(i==1){
				d=4;
			}
		}else{
			j++,d=1;
		}
		if(score[s]==k){
			cout<<j<<" "<<i;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
