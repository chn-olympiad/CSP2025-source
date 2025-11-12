#include<bits/stdc++.h>
using namespace std;
int n,m;
struct seats{
	int score,id;
}a[105];
bool cmp(seats x,seats y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+(n*m)+1,cmp);
	int r=0,c=1;
	bool flag=true;
	for(int i=1;i<=(n*m);i++){
		if(flag==true){
			r++;
		}else{
			r--;
		}
		if(a[i].id==1){
			cout<<c<<" "<<r;
			break;
		}
		if(r==n&&flag==true){
			c++;
			r++;
			flag=false;
		}
		if(r==1&&flag==false){
			c++;
			r--;
			flag=true;
		}
		
	}
    fclose(stdin);
	fclose(stdout);
	return 0;
}
