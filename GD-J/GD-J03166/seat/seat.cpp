#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct xx{
	int y;
	bool b;
};
bool cmp(xx x,xx y){
	return x.y>y.y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	vector<xx>a;
	int n,m;
	scanf("%d%d",&n,&m);
	a.resize(n*m+1);
	for(int i=1;i<=n*m;i++){
		if(i==1){
			a[i].b=true;
			scanf("%d",&a[i].y);
		}
		else{
			a[i].b=false;
			scanf("%d",&a[i].y);
		}
	}
	sort(a.begin()+1,a.end(),cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(!a[i].b){
			if(y%2==1){
				if(x+1>n){
					y++;
				}
				else x++;
			}
			else{
				if(x-1<1){
					y++;
				}
				else x--;
			}
		}
		else break;
	}
	printf("%d %d",y,x);
	return 0;
}
