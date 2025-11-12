#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	int a[n*m]={};
	int ss;
	cin>>ss;
	a[0]=ss;
	int h=1,l=1;
	bool falg=true;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m);
	if(a[n*m-1]==ss){
		cout<<l<<h;
		return 0;
	}
	for(int i=n*m-1;i>=0;i--){
		cout<<i<<endl;
		if(a[i]==ss){
			cout<<l<<" "<<h;
			break;
		}
		bool f=true;
		if(falg){
			if(h==n){
				l++;
				falg=false;
				f=false;
				if(a[i-1]==ss){
					cout<<l<<" "<<h;
					break;
				}
			}
		}else if(f){
			if(h==1){
				l++;
				falg=true;
				f=false;
				if(a[i-1]==ss){
					cout<<l<<" "<<h;
					break;
				}
			}
		}
		if(falg&&f){
			h++;
		}else if(f){
			h--;
		}
	}
	return 0;
}

