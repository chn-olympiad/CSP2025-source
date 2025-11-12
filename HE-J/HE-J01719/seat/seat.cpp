#include <bits/stdc++.h>
using namespace std;
int a[150];
struct sj{
	int c1,r1;
	int gr;
};
sj b[150];
bool cmp(int a,int b){
	if(a!=b){
		return a>b;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r;
	cin>>c>>r;
	for(int i=1;i<=c*r;i++){
		cin>>a[i];
	}
	int ar=a[1];
	sort(a+1,a+c*r+1,cmp);
	for(int i=1;i<=c*r;i++){
		b[i].gr=a[i];
	}
	for(int i=1;i<=c;i++){
		if(i%2==1){
			for(int j=1;j<=r;j++){
				b[(i-1)*2+j].c1=i;
				b[2*(i-1)+j].r1=j;
				//b[i*j].gr=a[]
			}
		}
		else{
			for(int j=r;j>=1;j--){
				b[((i-2)*2+j+(2*(r-j+1)-1))].c1=i;
				b[((i-2)*2+j+(2*(r-j+1)-1))].r1=j;	
			}
		}
	}
	for(int i=1;i<=c*r;i++){
		if(b[i].gr==ar){
			cout<<b[i].c1<<" "<<b[i].r1;
		}
	}
	return 0;
} 
