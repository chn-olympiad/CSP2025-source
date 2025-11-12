#include <bits/stdc++.h>
using namespace std;
int cmd(int a,int b){
	return a>b; 
}
int main()
{
	int w,h,wo,b[105]={},q=0;
	cin>>w>>h>>wo;
	for(int i=0;i<w*h-1;i++){
		cin>>b[i];
	}
	sort(b,b+w*h,cmd);
	for(int i=0;i<w*h-1;i++){
		if(wo>b[i]){
			q=i;
			break;
		}
	}
	int x=1,y=1;
	for(int i=0;i<h/2;i++){
		for(int j=0;j<w;j++){
			if(q==0){
				cout<<x<<' '<<y;
				return 0;
			}
			if(j!=w-1){
			y++;
		}
			q--;
		}
		x+=1;
		for(int j=w;j>0;j--){
			if(q==0){
				cout<<x<<' '<<y;
				return 0;
			}
			y--;
			q--;
		}
		x++;
	}
	if(h%2==1){
		for(int j=0;j<w;j++){
			if(q==0){
				cout<<x<<' '<<y+1;
				return 0;
			}
			y++;
			q--;
		}
	}
	return 0;
} 
