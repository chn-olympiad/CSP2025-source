#include<iostream>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[505],d=0,a=0,b=0;
	string s;
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	for(int j=0;j<n*n;j++){
		for(int i=0;i<n;i++){
			if(s[i]==0||d>c[i]){
				d++;
			}else{
				d=0,a++;
			}
		}
		if(a>=m)b++;
	}
	cout<<b;
	return 0;
}
	
