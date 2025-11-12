#include <bits/stdc++.h>
using namespace std;
/*
I like playing Naruto---- jia qiang uchiha madara!!!
*/
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    vector<int>sc(n*m);
    for(int i=0;i<n*m;i++){
    	cin>>sc[i];
	}
	int my=sc[0];
	sort(sc.begin(),sc.end(),greater<int>());
	vector<vector<int>>seat(n+1,vector<int>(m+1,0));
	int idx=0;
	for(int col=1;col<=m;col++){
		if(col%2==1){
			for(int row=1;row<=n;row++){
				seat[row][col]=sc[idx++];
			}
		}else{
			for(int row=n;row>=1;row--){
				seat[row][col]=sc[idx++];
			}
		}
	}
	for(int row=1;row<=n;row++){
		for(int col=1;col<=m;col++){
			if(seat[row][col]==my){
				cout<<col<<" "<<row;
				return 0;
			}
		}
	}
}
//#Shang4Shan3Ruo6Shui4
