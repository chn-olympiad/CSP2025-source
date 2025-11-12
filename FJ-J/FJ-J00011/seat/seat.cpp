#include<bits/stdc++.h>
using namespace std;
int grade[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int rgrade=0;
	for(int i=1;i<=n*m;i++){
		cin>>grade[i];
	}
	rgrade=grade[1];
	sort(grade+1,grade+n*m+1,greater<int>());
	int loca=0;
	for(int i=1;i<=n*m;i++){
		if(grade[i]==rgrade){
			loca=i;
			break;
		}
	}
	int now=1;
	for(int line=1;line<=m;line++){
		if(line%2){
			for(int row=1;row<=n;row++){
				if(now==loca){
					cout<<line<<' '<<row;
					return 0;
				}
				now++;
			}
		}
		else{
			for(int row=n;row>=1;row--){
				if(now==loca){
					cout<<line<<' '<<row;
					return 0;
				}
				now++;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
