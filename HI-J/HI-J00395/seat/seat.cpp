#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	string s,n,m;
	cin>>s>>n>>m;
	
	int cnt;
	for(int i=0;i<20;i++){
		for(int x=1;x<10;x++){
			for(int y=1;y<10;y++){
				if(s[i]>=10){
				y++;
				return 1;
			}
			if(y%2==0){
				x--;
			if(y%2==1) {
					x++;
					return 1;
				}
			} 
		}
	}
		cnt++;
}
		
	cout<<"第"<<cnt<<"个学生坐在第"<<"x"<<"行"<<"y"<<"列"<<endl;
	return 0;
}

