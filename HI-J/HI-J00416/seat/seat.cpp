#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;cin>>n>>m>>x;
	int a[n*m]={0};
	for(int i=0;i<n*m-1;i++) cin>>a[i];
	sort(a,a+n*m-1,greater<int>());
	if(n==1&&m==1||x>a[0]) cout<<1<<' '<<1;
	else{
		int n1=1,m1=1;
		bool f=false;
		for(int i=0;i<n*m-1;i++){
			if(f==false) n1++;
			else if(f==true) n1--;
			if(n1>n){
				m1++;
				n1--;
				f=true;
			}
			if(n1<1){
				m1++;
				n1++;
				f=false;
			}
			if(x<=a[i]&&x>=a[i+1]){
				cout<<m1<<' '<<n1;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
} 
