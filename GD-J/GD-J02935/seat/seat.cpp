#include <iostream>
#include <algorithm>
using namespace std;
int n,m,sr;
const int MAXN=105;
int a[MAXN];
bool abc(int a,int b){
	if(a<b){
		return false;
	}
	return true;
}
int main(){
	
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int len=n*m;
	cin>>sr;
	a[1]=sr;
	for(int i=2;i<=len;i++){
		cin>>a[i];
	}
	sort(a+1,a+len+1,abc);
	if(sr>50){
		for(int i=1;i<=len;i++){
			if(a[i]==sr){
				int l=i/n+1;
				int h=i%(2*n);
				if(h>n){
					h=2*n+1-h;
				}
				if(h==0){
					h=1;
				}
				if(i%n==0){
					l--;
				}
				cout<<l<<" "<<h;
			}
		}
	}else{
		for(int i=len;i>=1;i--){
			if(a[i]==sr){
				int l=i/n+1;
				int h=i%(2*n);
				if(h>n){
					h=2*n+1-h;
				}
				if(h==0){
					h=1;
				}
				if(i%n==0){
					l--;
				}
				cout<<l<<" "<<h;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}
