#include<bits/stdc++.h>
using namespace std;
bool cmp(int aa,int bb){
	if(aa>=bb){
		return true;
	}else{
		return false;
	}
}
int nn,mm,xr,wz;
int aaa[150];
int main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>nn>>mm;
	for(int i=1;i<=nn*mm;i++){
		cin>>aaa[i];
	}
	xr=aaa[1];
	sort(aaa+1,aaa+1+nn*mm,cmp);
	for(int i=1;i<=nn*mm;i++){
		//cout<<xr<<" "<<aaa[i]<<endl;
		if(aaa[i]==xr){
			wz=i;
			//cout<<i<<endl;
			break;
		}
	}
	//cout<<wz<<" "<<wz/nn<<" "<<nn-(wz%nn)<<endl;
	if((wz/nn)%2==0&&wz%nn>=1){
		cout<<wz/nn+1<<" "<<wz%nn;
	}else if((wz/nn)%2==0){
		cout<<wz/nn<<" "<<1;
	}
	if((wz/nn)%2==1&&wz%nn>=1){
		cout<<wz/nn+1<<" "<<nn-(wz%nn-1);
	}else if((wz/nn)%2==1){
		cout<<wz/nn<<" "<<nn;
	}
	return 0;
} 
