#include<bits/stdc++.h>
using namespace std;
long long smallR,hisseat,l,h,sr,n,m,a[110];
int main(){
	 freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//------------------------------------------------------
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		long long x;
		cin>>x;
		a[i]=x;
		if(i==1){
		smallR=x;
		}
	}
	sort(a+1,a+n*m+1);
	for(long long i=1;i<=n*m;i++){
		if(a[i]==sr){
			hisseat=i;
			}
	}
	l=hisseat/m+1;
	h=hisseat%m;
	if(h==0){
		l--;
		}
	cout<<l<<" ";
	if(h==0&&l%2==0){
		h++;
		cout<<h;
		}
		else if(h==0&&l%2!=0){
			h+=n;
			cout<<h;
			}
			else cout<<h;
	//------------------------------------------------------
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
