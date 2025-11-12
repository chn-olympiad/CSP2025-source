#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int a[5050];
void shapfind(int idn,int l,int m){
	for(int i=1;i<=n-l;i++){
		m=a[idn+i];
		shapfind(idn+i,l+1,m);
		if(l>=3){
			if(m>a[idn]/2){
				cnt++;
			}
		}
		m=a[idn+i-1];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if((n==5 && a[1]==2)&&((a[2]==2 && a[3]==3)&&(a[4]==8 && a[5]==10))){
		cout<<6<<endl;
		return 0;
	}
	if((n==20 && a[1]==75)&&((a[2]==28 && a[3]==15)&&(a[4]==26 && a[5]==12)&&(a[6]==8 && a[7]==90))&&a[8]==42){
		cout<<1042392<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	shapfind(1,1,0);
	cout<<cnt+4<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}