#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
bool cmp(int p,int q){return p>q;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int o=n*m;
	for(int i=1;i<=o;i++){
		int x;scanf("%d",&x);
		a.push_back(x);
	}
	int st_test=a[0];
	sort(a.begin(),a.end(),cmp);
	int x=1,y=1;
	for(int i=0;i<o;i++){
		if(a[i]==st_test){
			printf("%d %d",y,x);
			break;
		}
		if(y%2==1){
			x+=1;
			if(x>n) {
				x-=1;
				y++; 
			}
		}else{
			x-=1;
			if(x<=0){
				x=1;
				y++;
			}
		}
	}
	return 0;
}
