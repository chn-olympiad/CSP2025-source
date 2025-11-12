#include <bits/stdc++.h>

using namespace std;
long long n,m,cnt=0;
struct stu{
	long long c;
	bool flag;
};
stu g[100005];
void so(int v){
	for(int i=1;i<v;i++){
		for(int j=2;j<=v;j++){
			if(g[j].c>=g[j-1].c){
				stu t=g[j];
				g[j]=g[j-1];
				g[j-1]=t;
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>g[i].c;
		g[i].flag=false;
	}
	g[1].flag=true;
	so(n*m);
	long long o1=1,om=m,oc=1;
	for(int i=1;i<=n;i++){
		for(int j=o1;j<=om;j+=oc){
			if(j==om){
				long long t=om;
				om=o1;
				o1=om;
				if(i%2==1){
					oc=1;
				}else{
					oc=-1;
				}
			}
			cnt++;
			if(g[cnt].flag==true){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
