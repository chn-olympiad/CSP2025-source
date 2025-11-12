#include<bits/stdc++.h> 
using namespace std;
const int N=1e6;
int b[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int s=n*m;
	for (int i=1;i<=s;i++){
		cin>>b[i];
	}
	int z1,z=b[1];
	sort(b+1,b+s+1);
	int c=1;
	for (int i=s;i>=0;i--){
		if (z==b[i]){
			z1=c;
		}
		c++;
	}
	int yu,su;
	yu=z1%m;
	su=z1/m+1;
	if (yu==0){
		if (su%2==0){
			cout<<su-1<<" "<<1;
		}else{
			cout<<su-1<<" "<<m;
		}
	}else{
		if (su%2==0){
			cout<<su<<" "<<m-yu+1;
		}else{
			cout<<su<<" "<<yu;
		}
		
	}
	return 0;
}
