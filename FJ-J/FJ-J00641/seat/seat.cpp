#include<bits/stdc++.h>
using namespace std;

int chengji[110];
int nh,ml,zwh=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>nh>>ml;
	
	for(int i=1;i<=nh*ml;i++){
		cin>>chengji[i];
		
		if(chengji[i]>chengji[1]){
			zwh++;
		}
	}
	
	if(zwh<=nh){
		cout<<1<<" "<<zwh;
	}else{
		if(zwh%nh==0){
			cout<<zwh/nh<<" ";
			
			if((zwh/nh)%2==0){
				cout<<1;
			}else{
				cout<<nh;
			}
		}else{
			cout<<zwh/nh+1<<" ";
			
			if((zwh/nh+1)%2==0){
				cout<<nh-(zwh%nh)+1;
			}else{
				cout<<zwh%nh;
			}
		}
	}
	
	return 0;
}
