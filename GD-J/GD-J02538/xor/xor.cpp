#include <bits/stdc++.h>
using namespace std;
int n,k,s=1;
int w[500010],f[500010],x[500010],y[500010];
struct q{
	int x,y;
};
q t[500010];
//bool c(q a,q b){
//	return a.y<b.y;
//}
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	f[1]=w[1];
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]^w[i];
		//cout<<f[i];
	}
	int h=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[j]-f[i-1]==k||w[i]==k){
				//cout<<f[j]<<" "<<f[i]<<" ";
				t[h].x=i;
				t[h].y=j;
				h++;
			}
			break;
		}
	}
	//sort(t,t+h);
	for(int i=0;i<h;i++){
		for(int j=i;j<h-1;j++){
			if(t[j].y>t[j+1].y){
				swap(t[j].x,t[j+1].x);
				swap(t[j].y,t[j+1].y);
			}
		}
	}
	cout<<h;
	int m=t[1].y;
	for(int i=2;i<=h;i++){
		if(t[i].x>m){
			m=t[i].y;
			s++;
		}	
	}
	cout<<s;
	return 0;
}
