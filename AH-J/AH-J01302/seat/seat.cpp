#include<bits/stdc++.h>
using namespace std;
struct jg{
	int number,score;
};
jg a[105];
bool cmp(jg x,jg y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].number=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	bool flag=0;
	for(int i=1;i<=n*m&&a[i].number!=1;i++){
		//j=i;
	//	cout<<x<<" "<<y<<endl;
		if(y==n){
			if(flag==0){
				flag=1;
				x++;
			}else{
				flag=0;
				if(x%2==0){
					y--;
				}else{
					y++;
				}
			}
		}else if(y==1&&x!=1){
			if(flag==0){
				flag=1;
				x++;
			}else{
				flag=0;
				if(x%2==0){
					y--;
				}else{
					y++;
				}
			}
		}else{
			if(x%2==0){
				y--;
			}else{
				y++;
				
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
