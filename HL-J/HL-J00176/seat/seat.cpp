#include <bits/stdc++.h>

using namespace std;
bool cmp(int a,int b){
	return a>b;
}

int cheng[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>n>>m;
	int p;
	int sx,sy;
	for(int i=0;i<n*m;i++){
		cin >>cheng[i];
	}
	int s=cheng[0];
	sort(cheng,cheng+n*m,cmp);
	for(int i=0;i<=n*m;i++){
		if(cheng[i]==s){
			p=i+1;
		}
	}
	int index=0;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				index++;
				if(index==p){
					sx=i;
					sy=j;
				}	
			}
		}else{
			for(int j=1;j<=m;j++){
				index++;
				if(index==p){
					sx=i;
					sy=j;
				}
			}
		}
	}
	cout <<sx<<' '<<sy;
	return 0;
}