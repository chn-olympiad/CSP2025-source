#include <iostream>
#include <algorithm>
using namespace std;
int c=1,r=1;//Ð¡RµÄ×ùÎ» x,y 
int tc=1,tr=1;
bool cmp(int ta,int tb){
	return ta>tb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1000];
	int sr=0;
	cin>>n>>m;
	int tmp=n*m;
	for(int i=1;i<=tmp;i++){
		cin>>a[i];
		if(i==1){
			sr=a[i];
		}
	}
	if((sr==100)||(n==1||m==1)){
		cout<<c<<" "<<r;
		return 0; 
	}
	sort(a+1,a+tmp+1,cmp);
	for(int i=1;i<=tmp;i++){
		if(a[i]==sr){
			if(r<n){
				r++;
				if(r==n)continue;
			}else if(r==n&&c==tc){
				c++;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
