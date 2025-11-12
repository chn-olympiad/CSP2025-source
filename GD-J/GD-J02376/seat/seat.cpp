#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,fl;
	cin>>n>>m;
	int b[n*m-1];
	for(int i=0;i<n*m;i++){
		cin>>b[i];
		fl=b[0];
	}
	sort(b-1,b+n*m-1);
	int cnt=n*m-1,ffl=0;
	for(int i=0;i<n;i++){
		if(ffl==1){
			for(int j=0;j<m;j++){
				if(b[cnt]==fl){
					cout<<i+1<<' '<<j+1;
					}
					cnt--;
			}
			ffl=1;
		}else{
			for(int j=m-1;j>=0;j--){
				if(b[cnt]==fl){
					cout<<i+1<<' '<<j+1;
					}
					cnt--;
			}
			ffl=0;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
