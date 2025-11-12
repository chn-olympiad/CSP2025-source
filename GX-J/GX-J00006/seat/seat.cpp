#include<bits/stdc++.h>

using namespace std;

int n,m,c,r;
int f[110];
int d;
int l;

int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);

cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>f[i];
}
l=f[1];
for(int i=1;i<=n*m;i++){
	for(int j=1;j<=n*m-i;j++){
		if(f[j]<f[j+1]){
			int a=f[j];
			f[j]=f[j+1];
			f[j+1]=a;
		}
	}
}
for(int i=1;i<=n*m;i++){
	if(f[i]==l){
		d=i;
	}
}

c=d/m;
if(d!=m) c++;
r=d%m;

if(c%2==0) r=n-r+1;

cout<<c<<" "<<r<<endl;

return 0;

}
