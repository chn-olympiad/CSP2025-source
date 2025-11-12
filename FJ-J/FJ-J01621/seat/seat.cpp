#include<bits/stdc++.h>
using namespace std;
const int N=105;
int hang,lie,score[N],rh,rl;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>hang>>lie;
	int n=hang*lie;
	for(int i=1;i<=n;i++)cin>>score[i];
	int r=1;
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(score[j]<score[j+1]){
				if(r==j)r=j+1;
				else if(r==j+1)r=j;
				swap(score[j],score[j+1]);
			}
		}
	}
//	cout<<r<<endl;
	r-=1;
	int dsb=r%hang;
	int cnm=r/hang;
//	cout<<dsb<<' '<<cnm<<endl;
	rl=cnm+1;
	if(rl%2==1)rh=dsb+1;
	else rh=hang-dsb;
	cout<<rl<<' '<<rh;
}
