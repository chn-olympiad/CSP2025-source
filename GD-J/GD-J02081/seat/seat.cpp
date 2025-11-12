//?NM xiao yu 10 dou wo wan ne
//1 -> 1,1 2 -> 1,2 ,5 - > 2,1
//no idea with the math method..
//wait n < 10 m < 10 i can have some easy baoli 

#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i ++){
		cin>>a[i];
	}
	int t;
	int b = a[1];
	sort(a+1,a+n*m+1,cmp);//why so keep on sorting upsidedown
	for(int i = 1;i <= n*m;i ++){
		if(a[i] == b){
			t = i;
			break;
		}
	}
	//cout<<t<<endl;
	int dx=1,dy=0,v=1;
	for(int i = 1;i <= t;i ++){
		dy += v;
		//cout<<dy<<" "<<dx<<endl;
		if(dy > n || dy < 1) {
			v *= -1;
			dx++;
			dy += v;
			//cout<<"next"<<endl;
		}
		
	}
	cout<<dx<<" "<<dy; 
	return 0; 
}
//have you guys found that if you look at the squares in T2 you can find gray dots?	
//AWA
//a bit shit,but finish in 20min
