#include<bits/stdc++.h>
using namespace std;
int a[105],b,c,d,v,t,u;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>b>>c;
	d=b*c;
	for(int i=1;i<=d;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+1+d,cmp);
	for(int i=1;i<=d;i++){
		if(a[i]==t){
			v=i;
			break;
		}
	}
	while(1){
		if(v>b){
			v-=b;
			u++;
		}
		else{
			if(v==0){
				if(u%2==0) cout<<u<<' '<<1;
				else cout<<u<<' '<<b;
			}
			else{
				if(u%2==0) cout<<u+1<<' '<<v;
				else cout<<u+1<<' '<<b-v+1;
			}
			return 0;
		}
	}
	return 0;
} 
