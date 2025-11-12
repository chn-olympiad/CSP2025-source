#include<bits/stdc++.h>
using namespace std;
int fs[110],sR,lR,hR,h,l;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>h>>l;
	for(int i=1;i<=h*l;i++)cin>>fs[i];
	int xR=fs[1];
	sort(fs+1,fs+h*l+1,cmp);
	for(int i=1;i<=h*l;i++){
		if(xR==fs[i]){
			sR=i;
			break;
		}
	}
	if(sR%h==0){
		lR=sR/h;
		if(lR%2==1)hR=h;
		else hR=1;
	}
	else{
		lR=sR/h+1;
		if(lR%2==1)hR=sR-(lR-1)*h;
		else hR=h-(sR-(lR-1)*h)+1;
	}
	cout<<lR<<" "<<hR;
	return 0;
}
