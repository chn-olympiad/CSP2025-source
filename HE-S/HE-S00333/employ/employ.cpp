#include <iostream>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[500],c[500],f=0,t=0,p=0;
	char s[100];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		a[i]=c[i];
	}
	for(int i=0;i<n;i++){
		if(c[i]==-1){
			continue;
		}
		if(s[i]=='1'){
			t++;
			f=0;
		}else{
			f++;
		}
		for(int i=0;i<n;i++){
			if(f>=c[i]){
				f++;
				c[i]=-1;
			}
		}
	}
	if(t>=m){
		p++;
	}
	cout<<p%998<<" "<<p%244<<" "<<p%353;
}
