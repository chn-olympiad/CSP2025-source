#include<bits/stdc++.h>
using namespace std;
bool aaaaa(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int sx,sy;
	cin>>sx>>sy;
	int a[sx*sy];
	int n[sx][sy];
	bool hh=true;
	for(int i=0;i<sx*sy;i++){
		cin>>a[i];
	}
	int rp=a[0];
	sort(a,a+sx*sy,aaaaa);
	for(int i=0;i<sx;i++){
		bool contin=false;
		if(hh){
			for(int j=0;j<sy;j++){
				if(a[i*sy+j]==rp){
					cout<<i+1<<" "<<j+1;
					contin=true;
					break;
				}
			}
			if(contin){
				break;
			}
			hh=false;
			continue;
		}else{
			for(int j=sy-1;j>=0;j--){
				if(a[i*sy+sy-j-1]==rp){
					cout<<i+1<<" "<<j+1;
					contin=true;
					break;
				}
			}
			if(contin){
				break;
			}
			hh=true;
		}
	}
	return 0;
}
