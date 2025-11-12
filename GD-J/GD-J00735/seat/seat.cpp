#include<bits/stdc++.h>
using namespace std;
int n,m,pm,hz=1,b[102],Rpoints;
bool jo=false;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int jsq=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>b[i];
	Rpoints=b[1];
	sort(b+1,b+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(b[i]==Rpoints){
			pm=n*m-i+1;
		}
	}
	while(jsq<=pm){
		if(hz<n&&jo==false){
			hz++;
			jsq++;
		}
		if(hz>1&&jo==true)
		{
			hz--;
			jsq++;
		}
		if(jsq==pm){
		
		break;	
		}
		if(hz==n){
			jsq+=2;
		jo=true;	
		}
		if(hz==1){
			jsq+=2;
			jo=false;
		}	
	}
	cout<<(ceil(float(pm)/n))<<" "<<hz<<endl;	
	return 0;
} 
