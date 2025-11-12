#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int h,l,R,cj=0,Rh,Rl,Ri,o=0;
	cin>>h>>l;
	for(int i=1;i<=h*l;i++){
		cin>>a[i];
	}
	R=a[1];
	for(int i=1;i<=h*l;i++){
		for(int j=1;j<=h*l;j++){
			if(a[j]<a[j+1]){
				cj=a[j];
				a[j]=a[j+1];
				a[j+1]=cj;
			}
		}
	}
	for(int i=1;i<=h*l;i++){
		if(a[i]==R){
			Ri=i;
		}
	}
	if((Ri%l)%2==0&&Ri%l!=0){
		Rl=Ri%l+1;
	}
	else if(Ri%l==0){
		Rl=Ri/l;
	}
	else{
		Rl=Ri/l+1;
	}
	cout<<Rl<<" ";
	if(Rl%2==0){
		for(int i=0;i<=Ri;i++){
			if(Ri>=h){
				Ri-=h;
			}
			else{
				break;
			}
		}
		Rh=h-Ri+1;
	}
	else{
		for(int i=0;i<=Ri;i++){
			if(Ri>h){
				Ri-=h;
			}
			else{
				break;
			}
		}
		Rh=Ri;
	}
	cout<<Rh;
	
	return 0;
}
