#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
	int num,gra;
	
}text[101];
bool pai(stu a,stu b){
	return a.gra>b.gra;
}
int px,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>text[i].gra;
		text[i].num=i;
	}
	sort(text+1,text+n*m+1,pai);
	for(int i=1;i<=n*m;i++){
		if(text[i].num==1){
			px=i;
			break;
		}
	}
	while(px>=n){
		x++;
		px-=n;
	}
	if(!px){
		if(x%2==1){
			y=n;
		}
		else{
			y=1;
		}
	}
	else{
		
		if(x%2==1){
			y=n-px+1;
		}
		else{
			y=px;
		}
		x++;
	}
	cout<<x<<" "<<y;
	return 0;
}