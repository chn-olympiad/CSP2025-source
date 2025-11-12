#include<bits/stdc++.h>
using namespace std;
int wei[10+5][10+5];
set<int> a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int flag;
	for(int i=1;i<=n*m;i++){
		int ru=0;
		cin>>ru;
		if(i==1)  flag=ru;
		a.insert(ru);
	}
	int j=0,di=0;
	for(auto i=a.end();i!=a.begin();i--){
		if(*i==flag){
			di+=j;
		}
		j++;
	}
	int hang=0,lie=0;
	if(di>=n){
	    if(di%m==0){
			lie=di/m;
			if(lie%2==0){
				hang=1;
			}else hang=m;
		}else{
			lie=di/m+1;
			hang=di%m;
			if(lie%2==0){
			hang=m-hang+1;
			}
		} 	
	}else{
		hang=di;
		lie=1;
	} 	
	cout<<lie<<' '<<hang;
	return 0;
} 
