#include <bits/stdc++.h>
using namespace std;

int n,m,r_s,man;
int l=1,h,f=1;
int score[101]={};

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin >> n >> m;
	
	for(int i = 1;i<=n*m;i++){
		cin >> score[i];
	}
	r_s = score[1];
	
	for(int i = 1;i<=n*m;i++){
		if(score[i]>=r_s) man++;
	}
	
	while(man>n){
		l++;
		man-=n;
		f*=-1;
	}
	if(f==1){//´ÓÇ°Íùºó 
		h=man;
	}
	else{
		h=m-man-1;
	}
	cout << l << ' ' << h;
	return 0;
} 
