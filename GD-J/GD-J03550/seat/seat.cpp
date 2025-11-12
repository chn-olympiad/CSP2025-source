#include<bits/stdc++.h>
using namespace std;
bool turn(bool a){
	if(a==0)a=1;
	else a=0;
	return a;
}
int main(){
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	int m,n,higher=1,a,r;
	bool plus=1;
	int now_x=1,now_y=1;
	fin>>n>>m;
	fin>>r;
	for(int i=1;i<n*m;i++){
		fin>>a;
		if(a>r)higher++;
	}
	
	if(higher>n){
		if(higher%n!=0){
		    now_x+=higher/n;
		    higher%=n;
		}
		else {
		    now_x+=(higher/n)-1;
		    higher=n;
	    }
		if(now_x%2==1)plus=1;
		else plus=0;
		if(plus==1){
			now_y=higher;
		}
		else{
			now_y=n-higher+1;
		}
		cout<<now_x<<" "<<now_y;
	}
	else{
		cout<<now_x<<" "<<higher;
	}
	fin.close();
	fout.close();
}
